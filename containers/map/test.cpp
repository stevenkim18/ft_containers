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
    std::cout << "]" << RESET << " ";

    (void)mm;
    // std::cout << RED << "[ ";
    // for (typename ft::Map<T>::iterator it = ml.begin(); it != ml.end(); ++it)
    //     std::cout << *it << " ";
    // std::cout << "]" << RESET << std::endl;
}

int main(void)
{
    std::map<int, std::string> om;
    ft::Map<int, std::string> mm;

    om.insert(std::make_pair<int, std::string>(10, "sda"));  //fm.insert(std::make_pair<int, std::string>(10, "sda"));     
    om.insert(std::make_pair<int, std::string>(20, "asd"));  //fm.insert(std::make_pair<int, std::string>(20, "sda"));     
    om.insert(std::make_pair<int, std::string>(3, "fghn"));   //fm.insert(std::make_pair<int, std::string>(3, "sda"));      
    om.insert(std::make_pair<int, std::string>(17, "vrv"));  //fm.insert(std::make_pair<int, std::string>(17, "sda"));     
    om.insert(std::make_pair<int, std::string>(15, "twer"));  //fm.insert(std::make_pair<int, std::string>(15, "sda"));     
    om.insert(std::make_pair<int, std::string>(13, "xcvb"));  //fm.insert(std::make_pair<int, std::string>(13, "sda"));     
    om.insert(std::make_pair<int, std::string>(2, "uyj"));   //fm.insert(std::make_pair<int, std::string>(2, "sda"));      
    om.insert(std::make_pair<int, std::string>(10, "wer"));  //fm.insert(std::make_pair<int, std::string>(10, "sda"));     
    om.insert(std::make_pair<int, std::string>(8, "xvv"));   //fm.insert(std::make_pair<int, std::string>(8, "sda"));      
    om.insert(std::make_pair<int, std::string>(19, "qwer"));  //fm.insert(std::make_pair<int, std::string>(19, "sda"));     
    om.insert(std::make_pair<int, std::string>(4, "dfg"));   //fm.insert(std::make_pair<int, std::string>(4, "sda"));      
    om.insert(std::make_pair<int, std::string>(8, "qwer"));   //fm.insert(std::make_pair<int, std::string>(8, "sda"));      
    om.insert(std::make_pair<int, std::string>(5, "zdf"));   //fm.insert(std::make_pair<int, std::string>(5, "sda"));      
    om.insert(std::make_pair<int, std::string>(1, "yert"));   //fm.insert(std::make_pair<int, std::string>(1, "sda"));      
    om.insert(std::make_pair<int, std::string>(11, "zsd"));  //fm.insert(std::make_pair<int, std::string>(11, "sda"));     
    om.insert(std::make_pair<int, std::string>(16, "uti"));  //fm.insert(std::make_pair<int, std::string>(16, "sda"));     

    print_all_element(om, mm);

}