#include <iostream>
#include "BST.hpp"

int main(void)
{
    BST<std::pair<int, std::string> > bst;

    bst.insert(std::make_pair<int, std::string>(5, "vds"));
    bst.insert(std::make_pair<int, std::string>(10, "eqw"));
    bst.insert(std::make_pair<int, std::string>(2, "asdf"));
    bst.insert(std::make_pair<int, std::string>(7, "xvd"));
    bst.insert(std::make_pair<int, std::string>(13, "gte"));
    bst.insert(std::make_pair<int, std::string>(1, "fgv"));
    bst.insert(std::make_pair<int, std::string>(4, "dfs"));
    bst.insert(std::make_pair<int, std::string>(5, "afr"));
    bst.insert(std::make_pair<int, std::string>(9, "yth"));

    bst.print_in_order();

}