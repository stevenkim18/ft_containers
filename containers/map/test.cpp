#include <iostream>
#include <map>
#include "Map.hpp"

int main(void)
{
    std::map<int, std::string> om;
    ft::Map<int, std::string> fm;

    std::cout << "first = " << om.begin()->first << std::endl;
    std::cout << "second = " << om.begin()->second << std::endl;

    std::cout << "first = " << fm.begin()->first << std::endl;
    std::cout << "second = " << fm.begin()->second << std::endl;

}