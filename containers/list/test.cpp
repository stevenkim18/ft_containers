#include <iostream>
#include <list>
#include "List.hpp"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

template <typename T>
void    print_ori_my_value(std::string const &str, T ori, T my)
{
    std::cout << GREEN << "ori " << str << " = " << ori << RESET << std::endl;
    std::cout << RED <<" my " << str << " = " << my << RESET << std::endl;
}

template <typename T>
void    print_all_element(std::list<T> &ol, ft::List<T> &ml)
{   
    std::cout << GREEN << "[ ";
    for (typename std::list<T>::iterator it = ol.begin(); it != ol.end(); it++)
        std::cout << *it << " ";
    std::cout << " ]" << RESET << std::endl;

    std::cout << RED << "[ ";
    for (typename ft::List<T>::iterator it = ml.begin(); it != ml.end(); ++it)
        std::cout << *it << " ";
    std::cout << " ]" << RESET << std::endl;
}

int main(void)
{
    std::list<int> ol;
    ft::List<int> ml;

    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());

    std::cout << "-------------------------------------------" << std::endl;

    ol.push_back(1);
    ml.push_back(1);

    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());

    std::cout << "-------------------------------------------" << std::endl;

    ol.push_back(2);
    ml.push_back(2);
    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());

    std::cout << "-------------------------------------------" << std::endl;

    ol.push_back(3);
    ml.push_back(3);
    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());

    print_all_element(ol, ml);
    for (ft::List<int>::iterator it = ml.begin(); it != ml.end(); ++it)
        std::cout << "val = " << *it << " arr = " << &*it << std::endl;
    
    std::cout << "&end() = " << &(*ml.end()) << std::endl;
    

    std::cout << "-------------------------------------------" << std::endl;

    ol.pop_back();
    ml.pop_back();
    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());

    std::cout << "-------------------------------------------" << std::endl;

    ol.pop_back();
    ml.pop_back();
    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());

    std::cout << "-------------------------------------------" << std::endl;

    ol.pop_back();
    ml.pop_back();
    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());
    

}