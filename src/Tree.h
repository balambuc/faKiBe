//
// Created by Bence Bárdosi on 13/12/17.
//

#ifndef FAKIBE_TREE_H
#define FAKIBE_TREE_H

#include <memory>
#include <string>
#include <sstream>


class Tree {
    struct Node;
    using nodePtr = std::unique_ptr<Node>;

private:
    struct Node {
        int key;
        nodePtr left;
        nodePtr right;

        explicit Node(int k = 0, nodePtr l = nullptr, nodePtr r = nullptr) : key(k),
                                                                             left(std::move(l)),
                                                                             right(std::move(r)) {}
    };

    nodePtr t;

    friend void tostring(const nodePtr&, int, std::stringstream&);

    static nodePtr sink(int, std::pair<size_t, size_t>, const std::string&);

public:
    explicit Tree(nodePtr node = nullptr) : t(std::move(node)) {}
    explicit Tree(std::string str) : t(from_string(std::move(str))) {}

    explicit Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;

    ~Tree() = default; //doesn't need to manually delete the nodes as they are encapsulated in std::unique_ptr

    /**
     * Node factory function
     * @param key : key of node to be constructed
     * @return : a pointer to a node with the following fields
     *          (key = key, left = right = nullptr)
     */
    static nodePtr make_node(int key) { return nodePtr(new Node(key)); }

    std::string to_string() const {
        std::stringstream ss;
        tostring(t, 0, ss);
        return ss.str();
    }

    static nodePtr from_string(std::string&&);
};


#endif //FAKIBE_TREE_H
