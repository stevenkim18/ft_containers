#include <iostream>
#include "BST.hpp"
#include "Pair.hpp"

int main(void)
{
    // BST<ft::Pair<int, std::string> > bst;

    // bst.insert(ft::Pair<int, std::string>(5, "vds"));
    // bst.insert(ft::Pair<int, std::string>(10, "eqw"));
    // bst.insert(ft::Pair<int, std::string>(2, "asdf"));
    // bst.insert(ft::Pair<int, std::string>(7, "xvd"));
    // bst.insert(ft::Pair<int, std::string>(13, "gte"));
    // bst.insert(ft::Pair<int, std::string>(1, "fgv"));
    // bst.insert(ft::Pair<int, std::string>(4, "dfs"));
    // bst.insert(ft::Pair<int, std::string>(5, "afr"));
    // bst.insert(ft::Pair<int, std::string>(9, "yth"));

    // bst.print_in_order();

    // ft::Pair<int, std::string> pair (10, "sadf");
    // ft::Pair<int, std::string> pair2 (20, "asd");

    // std::cout << std::boolalpha;
    // std::cout << (pair < pair2) << std::endl;
    // std::cout << (pair > pair2) << std::endl;

    BST<int> bst;

    bst.insert(10);
    bst.insert(5);

}