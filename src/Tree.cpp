//
// Created by Bence Bárdosi on 13/12/17.
//

#include "Tree.h"
#include <iostream>
#include <algorithm>


std::pair<char, char> brackets[3]{{'{', '}'},
                                  {'[', ']'},
                                  {'(', ')'}};


void tostring(const Tree::nodePtr& t, int n, std::stringstream& sstream) {
    if (t != nullptr)
    {
        sstream << brackets[n].first;
        tostring(t->left, (n + 1) % 3, sstream);
        sstream << t->key;
        tostring(t->right, (n + 1) % 3, sstream);
        sstream << brackets[n].second;
    }
}

/**
 * Builds a tree from a given braket-notated string
 * @param str : input string to build tree from
 * @return : nodePtr to the root of the built tree
 */
Tree::nodePtr Tree::from_string(std::string&& str) {

    auto it = std::remove_if(str.begin(), str.end(),
                             [](char x)
                             { return isspace(x); });
    str.erase(it, str.end());

    try
    {
        return sink(0, {0, str.length()}, str);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Bad format!\n";
        return nullptr;
    }
}

/**
 * Create node and recursively assign its children
 * @param n : bracket-level
 * @param interval : pair(a, b) === [a, b), the range of the str that is being processed
 * @param str : input str
 * @return t : ptr to node that is created
 */
Tree::nodePtr Tree::sink(int n, std::pair<size_t, size_t> intv, const std::string& str) {

    n = (n + 1) % 3;

    if (intv.first - intv.second <= 1) // there is no node
        return nullptr;

    size_t closing = intv.first + 1;

    if (str[closing] == brackets[n].first) // there is a left child node
        for (int bracket_no = 0;
             closing < intv.second && !(str[closing - 1] == brackets[n].second && bracket_no == 0); ++closing)
        {
            if (str[closing] == brackets[n].first)
                ++bracket_no;
            else if (str[closing] == brackets[n].second)
                --bracket_no;
        }

    size_t opening = closing;
    while (opening < intv.second && str[opening] != brackets[n].first)
        ++opening;

    auto t = make_node(std::stoi(str.substr(closing, opening - closing)));
    t->left = sink(n, {intv.first + 1, closing}, str);
    t->right = sink(n, {opening, intv.second - 1}, str);

    return t;
}

