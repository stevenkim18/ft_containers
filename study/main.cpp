#include "BST.hpp"

# include <cstdlib>
# include <ctime>

int main(void)
{
    // BST<int> bst;

    // srand((unsigned int)time(NULL));

    // for (int i = 0; i < 100; i++)
    // {
    //     int num = rand();
    //     bst.insert(num % 100 + 1);
    // }
    // // system("pause");

    // bst.print_in_order();

    // std::cout << std::boolalpha;
    // std::cout << bst.search(1) << std::endl;
    // std::cout << bst.search(20) << std::endl;
    // std::cout << bst.search(17) << std::endl;

    // std::cout << "min = " << bst.find_min() << std::endl; 
    // std::cout << "max = " << bst.find_max() << std::endl; 

    // std::cout << "10 succeseeor = " << bst.successor(10) << std::endl;
    // std::cout << "20 succeseeor = " << bst.successor(20) << std::endl;
    // std::cout << "10 predecessor = " << bst.predecessor(10) << std::endl;
    // std::cout << "20 predecessor = " << bst.predecessor(20) << std::endl;

    // for (int i = 1; i <= 10; i++)
    // {
    //     if (bst.search(i * 10))
    //     {
    //         std::cout << i * 10 << " remove" << std::endl;
    //         bst.remove(i * 10);
    //     }
    // }

    // bst.print_in_order();

    // while(1)
    // {}

    BST<std::pair<int, std::string> > bst;

    bst.insert(std::make_pair(10, "afda"));
    bst.insert(std::make_pair(3, "asd"));
    bst.insert(std::make_pair(1, "aa"));
    bst.insert(std::make_pair(5, "aa"));
    bst.insert(std::make_pair(7, "aa"));

    bst.print_in_order();

}