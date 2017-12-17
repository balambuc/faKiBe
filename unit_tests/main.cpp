#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../src/Tree.h"

TEST_CASE("FaKiBe", "[mind2 fv egyszerre]"){
    std::string tests[] =
            {"",                                                //Üres string                   ^
             "3",                                               //Helytelen string1             |
             "{[(4{2})8(5)]10[(6)9(7{[13})]}",                  //Helytelen fa                  |
             "{}",                                              //Helyes üres fa                ^ Várt ki: ""
             "{3}",                                             //Helyes, 1magas fa             ^
             "{[(1)2(3)]4[(5)6(7)]}",                           //Helyes, 3magas teli fa        |
             "{1[2(3{4})]}",                                    //Helyes, csak jobbgyerek fa    |
             "{[({1}2)3]4}",                                    //Helyes, csak balgyerek fa     |
             "{[(4{2})8(5)]10[(6)9(7{[1]3})]}"};                //Helyes, átlagos fa            ^ Várt ki: bemenet

    SECTION("Hibás esetek (1-3)"){
        for (int test_no = 0; test_no < 3; ++test_no)
            CHECK(Tree(tests[test_no]).to_string() == "");
    }

    SECTION("Helyes, üres eset (4)"){
        CHECK(Tree(tests[3]).to_string() == "");
    }

    SECTION("Helyes, nem üres esetek (5-9)"){
        for (int test_no = 5; test_no < 9; ++test_no)
            CHECK(Tree(tests[test_no]).to_string() == tests[test_no]);
    }
}