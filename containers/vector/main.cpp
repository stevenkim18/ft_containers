#include "Vector.hpp"
#include <vector>
#include <limits>

# define RED "\033[1;31m"
# define RESET "\033[0m"

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
void print_all_my_vector_element(ft::Vector<T> v)
{
	typedef typename ft::Vector<T>::size_type type;
	std::cout << "[ ";
	for (type i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "]" << std::endl;
}

template <typename T>
void print_both_vector(std::vector<T> ori_v, ft::Vector<T> my_v)
{
	std::cout << "ori : ";
	print_all_origin_vector_element(ori_v);
	std::cout << RED << " my : ";
	print_all_my_vector_element(my_v);
	std::cout << RESET;
}

template <typename T>
void print_origin_my_fun(std::string const &str, T ori_value, T my_value)
{
	std::cout << "ori " << str << " = " << ori_value << std::endl;
	std::cout << RED << " my " << str << " = " << my_value << RESET << std::endl;
}

int main(void)
{
	// 기본 생성자
	std::vector<int> ori_v;
	ft::Vector<int> my_v;

	// size
	print_origin_my_fun("size()", ori_v.size(), my_v.size());

	// capacity
	print_origin_my_fun("capacity()", ori_v.capacity(), my_v.capacity());

	// max_size
	print_origin_my_fun("max_size()", ori_v.max_size(), my_v.max_size());

	std::cout << "=============== push_back ===============" << std::endl;

	// 1~8까지 vector에 추가
	for (int i = 1; i < 9; i++)
	{
		ori_v.push_back(i);
		my_v.push_back(i);
		print_origin_my_fun("size()", ori_v.size(), my_v.size());
		print_origin_my_fun("capacity()", ori_v.capacity(), my_v.capacity());
	}

	print_both_vector(ori_v, my_v);

	std::cout << "--------------- reserve ---------------" << std::endl;
	ori_v.reserve(9);
	my_v.reserve(9);
	print_origin_my_fun("size()", ori_v.size(), my_v.size());
	print_origin_my_fun("capacity()", ori_v.capacity(), my_v.capacity());

	// 9 10 추가
	for (int i = 9; i < 11; i++)
	{
		ori_v.push_back(i);
		my_v.push_back(i);
	}
	print_origin_my_fun("size()", ori_v.size(), my_v.size());
	print_origin_my_fun("capacity()", ori_v.capacity(), my_v.capacity());

	// 두 vector 원소들 출력
	print_both_vector(ori_v, my_v);

	// at 오버플로우 되었을 때 예외처리
	std::cout << "--------------- at ---------------" << std::endl;
	std::cout << "ori at() = ";
	try
	{ std::cout << ori_v.at(11) << std::endl; }
	catch(const std::exception& e)
	{ std::cout << "out of range!" << std::endl; }

	std::cout << RED << " my at() = ";
	try
	{ std::cout << ori_v.at(11) << std::endl; }
	catch(const std::exception& e)
	{ std::cout << "out of range!" << std::endl; }
	std::cout << RESET;

	while (!my_v.empty())
	{
		my_v.pop_back();
		std::cout << "size = " << my_v.size() << " cap = " << my_v.capacity() << std::endl;
	}
	my_v.pop_back();
}
