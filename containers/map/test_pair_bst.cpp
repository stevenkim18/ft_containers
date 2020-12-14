#include <iostream>
#include "BST.hpp"
#include "Pair.hpp"

int main(void)
{
    BST<ft::Pair<int, std::string> > bst;

    bst.insert(ft::Pair<int, std::string>(5, "vds"));
    bst.insert(ft::Pair<int, std::string>(10, "eqw"));
    bst.insert(ft::Pair<int, std::string>(2, "asdf"));
    bst.insert(ft::Pair<int, std::string>(7, "xvd"));
    bst.insert(ft::Pair<int, std::string>(13, "gte"));
    bst.insert(ft::Pair<int, std::string>(1, "fgv"));
    bst.insert(ft::Pair<int, std::string>(4, "dfs"));
    bst.insert(ft::Pair<int, std::string>(5, "afr"));
    bst.insert(ft::Pair<int, std::string>(9, "yth"));
    bst.insert(ft::Pair<int, std::string>(42, "edf"));
    bst.insert(ft::Pair<int, std::string>(20, "qwe"));
    bst.insert(ft::Pair<int, std::string>(30, "xcv"));
    bst.insert(ft::Pair<int, std::string>(15, "wer"));
    bst.insert(ft::Pair<int, std::string>(45, "gsd"));
    bst.insert(ft::Pair<int, std::string>(14, "cdd"));
    bst.insert(ft::Pair<int, std::string>(40, "sef"));

    bst.print_in_order();

    bst.remove(bst.search(20)->data);
    bst.remove(bst.search(42)->data);
    bst.remove(bst.search(40)->data);
    bst.remove(bst.search(1)->data);

    bst.print_in_order();

    // ft::Pair<int, std::string> pair (10, "sadf");
    // ft::Pair<int, std::string> pair2 (20, "asd");

    // std::cout << std::boolalpha;
    // std::cout << (pair < pair2) << std::endl;
    // std::cout << (pair > pair2) << std::endl;

    // BST<int> bst;

    // bst.insert(10);
    // bst.insert(5);

}