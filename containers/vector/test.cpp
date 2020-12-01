#include <iostream>
#include <vector>
#include "Vector.hpp"

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

template <typename T>
void print_all_origin_vector_element(std::vector<T> v)
{
	typedef typename std::vector<T>::size_type type;
	std::cout << "[ ";
	for (type i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "]" << std::endl;
}

template <typename T>
void print_all_my_vector_element(ft::Vector<T> &v)
{
	typedef typename ft::Vector<T>::size_type type;
	std::cout << "[ ";
	for (type i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "]" << std::endl;
}

template <typename T>
void print_both_vector(std::vector<T> ori_v, ft::Vector<T> &my_v)	// 와 인자로 그냥 my_v 넘기니 소멸자가 2번 호출 됨...
{																	// 그래서 &my_v로 바꿈. 레퍼런스로 넘겨주어야 함.
	std::cout << GREEN << "ori : ";
	print_all_origin_vector_element(ori_v);
	std::cout << RESET;
	std::cout << RED << " my : ";
	print_all_my_vector_element(my_v);
	std::cout << RESET;
}

template <typename T>
void print_origin_my_fun(std::string const &str, T ori_value, T my_value)
{
	std::cout << GREEN <<"ori " << str << " = " << ori_value << RESET << std::endl;
	std::cout << RED << " my " << str << " = " << my_value << RESET << std::endl;
}

int main(void)
{
	

}
