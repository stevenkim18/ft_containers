#include <iostream>

int main(void)
{
    std::pair<int, std::string> p1;
    std::pair<int, std::string> p2;

    p1.first = 1;
    p1.second = "aa";

    p2.first = 2;
    p2.second = "bb";

    std::cout << std::boolalpha;

    std::cout << (p1.first < p2.first) << std::endl;
    std::cout << (p1.second < p2.second) << std::endl;

}