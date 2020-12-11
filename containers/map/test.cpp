#include <iostream>
#include <map>
#include "Map.hpp"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

void    oneline(std::string const &title)
{
    std::cout << std::endl;
    std::cout << "-------------------- ";
    std::cout << title;
    std::cout << " -------------------- " << std::endl;
}

void    twoline(std::string const &title)
{
    std::cout << std::endl;
    std::cout << "==================== ";
    std::cout << title;
    std::cout << " ==================== " << std::endl;
}

template <typename K, typename T>
void    print_all_element(std::map<K, T> &om, ft::Map<K, T> &mm)
{   
    std::cout << GREEN << "[ ";
    for (typename std::map<K, T>::iterator it = om.begin(); it != om.end(); it++)
        std::cout << "(" << it->first << "," << it->second << ")";
    std::cout << " ]" << RESET << std::endl;

    std::cout << RED << "[ ";
    for (typename ft::Map<K, T>::iterator it = mm.begin(); it != mm.end(); ++it)
        std::cout << "(" << it->_key << "," << it->_value << ")";
    std::cout << " ]" << RESET << std::endl;
}

int main(void)
{
    std::map<int, std::string> om;
    ft::Map<int, std::string> mm;

    om.insert(std::make_pair<int, std::string>(10, "sda"));     mm.insert(ft::Pair<int, std::string>(10, "sda")); 
    om.insert(std::make_pair<int, std::string>(20, "asd"));     mm.insert(ft::Pair<int, std::string>(20, "asd")); 
    om.insert(std::make_pair<int, std::string>(3, "fghn"));     mm.insert(ft::Pair<int, std::string>(3, "fghn")); 
    om.insert(std::make_pair<int, std::string>(17, "vrv"));     mm.insert(ft::Pair<int, std::string>(17, "vrv")); 
    om.insert(std::make_pair<int, std::string>(15, "twer"));    mm.insert(ft::Pair<int, std::string>(15, "twer"));
    om.insert(std::make_pair<int, std::string>(13, "xcvb"));    mm.insert(ft::Pair<int, std::string>(13, "xcvb"));
    om.insert(std::make_pair<int, std::string>(2, "uyj"));      mm.insert(ft::Pair<int, std::string>(2, "uyj"));  
    om.insert(std::make_pair<int, std::string>(10, "wer"));     mm.insert(ft::Pair<int, std::string>(10, "wer")); 
    om.insert(std::make_pair<int, std::string>(8, "xvv"));      mm.insert(ft::Pair<int, std::string>(8, "xvv"));  
    om.insert(std::make_pair<int, std::string>(19, "qwer"));    mm.insert(ft::Pair<int, std::string>(19, "qwer"));
    om.insert(std::make_pair<int, std::string>(4, "dfg"));      mm.insert(ft::Pair<int, std::string>(4, "dfg"));  
    om.insert(std::make_pair<int, std::string>(8, "qwer"));     mm.insert(ft::Pair<int, std::string>(8, "qwer")); 
    om.insert(std::make_pair<int, std::string>(5, "zdf"));      mm.insert(ft::Pair<int, std::string>(5, "zdf"));  
    om.insert(std::make_pair<int, std::string>(1, "yert"));     mm.insert(ft::Pair<int, std::string>(1, "yert")); 
    om.insert(std::make_pair<int, std::string>(11, "zsd"));     mm.insert(ft::Pair<int, std::string>(11, "zsd")); 
    om.insert(std::make_pair<int, std::string>(16, "uti"));     mm.insert(ft::Pair<int, std::string>(16, "uti")); 

    print_all_element(om, mm);

    // ft::Map<int, std::string>::iterator oit = mm.begin();
    // ft::Map<int, std::string>::iterator oit2 = mm.end();

    // std::cout << (oit == oit2) << std::endl;

}