#include "BST.hpp"

int main(void)
{
    BST<int> bst;

    bst.insert(10);
    bst.insert(45);
    bst.insert(23);
    bst.insert(16);
    bst.insert(1);
    bst.insert(6);
    bst.insert(3);
    bst.insert(34);
    bst.insert(14);
    bst.insert(23);
    bst.insert(1);
    bst.insert(20);

    bst.print_in_order();

    std::cout << std::boolalpha;
    std::cout << bst.search(1) << std::endl;
    std::cout << bst.search(20) << std::endl;
    std::cout << bst.search(17) << std::endl;

    std::cout << "min = " << bst.find_min() << std::endl; 
    std::cout << "max = " << bst.find_max() << std::endl; 

    std::cout << "10 succeseeor = " << bst.successor(10) << std::endl;
    std::cout << "20 succeseeor = " << bst.successor(20) << std::endl;
    std::cout << "10 predecessor = " << bst.predecessor(10) << std::endl;
    std::cout << "20 predecessor = " << bst.predecessor(20) << std::endl;

    bst.remove(10);

    bst.print_in_order();

    bst.remove(20);

    bst.print_in_order();
}