#include "Vector.hpp"
#include <vector>
#include <limits>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
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

	// pop_back
	std::cout << "--------------- pop_back ---------------" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		ori_v.pop_back();
		my_v.pop_back();
	}

	print_both_vector(ori_v, my_v);
	print_origin_my_fun("size()", ori_v.size(), my_v.size());
	print_origin_my_fun("capacity()", ori_v.capacity(), my_v.capacity());

	std::cout << "=============== resize ===============" << std::endl;
	std::cout << "--------------- resize 10 ---------------" << std::endl;
	ori_v.resize(10);
	my_v.resize(10);

	print_both_vector(ori_v, my_v);
	print_origin_my_fun("size()", ori_v.size(), my_v.size());
	print_origin_my_fun("capacity()", ori_v.capacity(), my_v.capacity());

	std::cout << "--------------- resize 19 ---------------" << std::endl;
	ori_v.resize(19, 1);
	my_v.resize(19, 1);

	print_both_vector(ori_v, my_v);
	print_origin_my_fun("size()", ori_v.size(), my_v.size());
	print_origin_my_fun("capacity()", ori_v.capacity(), my_v.capacity());

	std::cout << "--------------- resize 6 ---------------" << std::endl;
	ori_v.resize(6);
	my_v.resize(6);

	print_both_vector(ori_v, my_v);
	print_origin_my_fun("size()", ori_v.size(), my_v.size());
	print_origin_my_fun("capacity()", ori_v.capacity(), my_v.capacity());

	std::cout << "=============== iterator ===============" << std::endl;
	std::vector<int>::iterator ori_iter = ori_v.begin();
	ft::Vector<int>::iterator my_iter = my_v.begin();

	std::cout << "--------------- begin & * ---------------" << std::endl;
	print_origin_my_fun("*iter", *ori_iter, *my_iter);

	std::cout << "--------------- change 1 to 100 ---------------" << std::endl;
	*ori_iter = 100;
	*my_iter = 100;
	print_both_vector(ori_v, my_v);

	std::cout << "--------------- ++ ---------------" << std::endl;
	std::vector<int>::iterator ori_tmp = ori_iter++;
	ft::Vector<int>::iterator my_tmp = my_iter++;

	print_origin_my_fun("tmp", *ori_tmp, *my_tmp);
	print_origin_my_fun("iter", *ori_iter, *my_iter);

	std::cout << "--------------- -- ---------------" << std::endl;
	ori_tmp = ori_iter--;
	my_tmp = my_iter--;

	print_origin_my_fun("tmp", *ori_tmp, *my_tmp);
	print_origin_my_fun("iter", *ori_iter, *my_iter);

	std::cout << "--------------- == != ---------------" << std::endl;
	std::cout << std::boolalpha;
	print_origin_my_fun("'=='", ori_tmp == ori_iter, my_tmp == my_iter);
	print_origin_my_fun("'!='", ori_tmp != ori_iter, my_tmp != my_iter);
	std::cout << std::noboolalpha;

	std::cout << "--------------- -> ---------------" << std::endl;
	std::vector<std::pair<int, std::string> > ov;
	ov.push_back(std::pair<int, std::string>(90, "Hello"));
	std::vector<std::pair<int, std::string> >::iterator o_iter = ov.begin();

	ft::Vector<std::pair<int, std::string> > mv;
	mv.push_back(std::pair<int, std::string>(90, "Hello"));
	ft::Vector<std::pair<int, std::string> >::iterator v_iter = mv.begin();

	print_origin_my_fun("-> first", o_iter->first, v_iter->first);

	std::cout << "--------------- + ---------------" << std::endl;
	ori_iter = ori_v.begin() + 3;
	my_iter = my_v.begin() + 3;
	print_origin_my_fun("+3", *ori_iter, *my_iter);

	std::cout << "--------------- - ---------------" << std::endl;
	ori_iter = ori_iter - 10;
	my_iter = my_iter - 10;
	print_origin_my_fun("-1", *ori_iter, *my_iter);
}
