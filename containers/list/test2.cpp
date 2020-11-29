#include <iostream>
#include <list>

bool    less(const int& a, const int& b) { return (a > b); }
template <typename N>
bool    compare (const N& a, const N& b) { return (a > b); }

int main(void)
{
    // std::list<int> l;

    // for (int i = 10; i > 0; i--)
    //     l.push_back(i);
    
    // // 10 9 8 7 6 5 4 3 2 1 
    // std::list<int>::iterator it = l.begin();
    // for (; it != l.end(); it++)
    //     std::cout << *it << " ";
    // std::cout << std::endl;

    
    // l.sort();

    // // 1 2 3 4 5 6 7 8 9 10
    // it = l.begin();
    // for (; it != l.end(); it++)
    //     std::cout << *it << " ";
    // std::cout << std::endl;

    // l.sort(less);
    // // 10 9 8 7 6 5 4 3 2 1
    // it = l.begin();
    // for (; it != l.end(); it++)
    //     std::cout << *it << " ";
    // std::cout << std::endl;
     
    std::list<std::string> l;
    l.push_back("one");
    l.push_back("two");
    l.push_back("three");

    l.sort();

    for (std::list<std::string>::iterator it = l.begin(); it != l.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    l.sort(compare<std::string>);

    for (std::list<std::string>::iterator it = l.begin(); it != l.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
        
}