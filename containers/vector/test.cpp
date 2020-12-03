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
	std::cout << "]";
}

template <typename T>
void print_all_my_vector_element(ft::Vector<T> &v)
{
	typedef typename ft::Vector<T>::size_type type;
	std::cout << "[ ";
	for (type i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "]";
}

template <typename T>
void print_both_vector(std::vector<T> ori_v, ft::Vector<T> &my_v)	// 와 인자로 그냥 my_v 넘기니 소멸자가 2번 호출 됨...
{																	// 그래서 &my_v로 바꿈. 레퍼런스로 넘겨주어야 함.
	std::cout << GREEN << "ori : ";
	print_all_origin_vector_element(ori_v);
	std::cout << RESET;
	std::cout << RED << " my : ";
	print_all_my_vector_element(my_v);
	std::cout << RESET << std::endl;
}

template <typename T>
void print_origin_my_fun(std::string const &str, T ori_value, T my_value)
{
	std::cout << GREEN <<"ori " << str << " = " << ori_value << RESET;
	std::cout << RED << " my " << str << " = " << my_value << RESET << std::endl;
}

int main(void)
{
	twoline("constructor");
	oneline("defalut constructor");

	std::vector<int> ol;
	ft::Vector<int> ml;

	print_both_vector(ol, ml);

	oneline("fill constructor");
	std::vector<int> fill_ol(10u, 42);
	ft::Vector<int> fill_ml(10u, 42);

	print_both_vector(fill_ol, fill_ml);
	
	oneline("range constructor");
	int arr[] = {18, 42, 18, 42};
	std::vector<int> range_ol(arr, arr + 4);
	ft::Vector<int> range_ml(arr, arr + 4);

	print_both_vector(range_ol, range_ml);

	oneline("copy constructer");
	std::vector<int> copy_ol(range_ol);
	ft::Vector<int> copy_ml(range_ml);

	print_both_vector(copy_ol, copy_ml);

	twoline("basic pushback and check size and capactiy");

	print_origin_my_fun("size", ol.size(), ml.size());

	oneline("push back 1 to 10");
	for (int i = 1; i < 11; i++)
	{
		ol.push_back(i);
		ml.push_back(i);
		print_origin_my_fun("size", ol.size(), ml.size());
		print_origin_my_fun("cap", ol.capacity(), ml.capacity());
	}

	print_both_vector(ol, ml);

	twoline("max size");

	print_origin_my_fun("max_size", ol.max_size(), ml.max_size());

	twoline("resize");
	
	print_both_vector(ol, ml);

	oneline("resize to 5");

	ol.resize(5);
	ml.resize(5);

	print_both_vector(ol, ml);

	oneline("resize to 9");

	ol.resize(9);
	ml.resize(9);

	print_both_vector(ol, ml);

	oneline("resize to 11 number 42");

	ol.resize(11, 42);
	ml.resize(11, 42);

	print_both_vector(ol, ml);

	twoline("empty");

	std::cout << std::boolalpha;
	
	print_origin_my_fun("empty", ol.empty(), ml.empty());

	oneline("clear and check empty");
	
	ol.clear(); 
	ml.clear();

	print_both_vector(ol, ml);
	print_origin_my_fun("empty", ol.empty(), ml.empty());

	twoline("reserve");

	for (int i = 1; i < 11; i++)
	{
		ol.push_back(i);
		ml.push_back(i);	
	}

	print_both_vector(ol, ml);
	print_origin_my_fun("size", ol.size(), ml.size());
	print_origin_my_fun("cap", ol.capacity(), ml.capacity());

	oneline("reserve to 20");

	ol.reserve(20);
	ml.reserve(20);

	print_origin_my_fun("cap", ol.capacity(), ml.capacity());

	for (int i = 11; i < 22; i++)
	{
		ol.push_back(i);
		ml.push_back(i);	
	}

	oneline("check when over cap");

	print_both_vector(ol, ml);

	print_origin_my_fun("cap", ol.capacity(), ml.capacity());

	twoline("operator[]");

	print_both_vector(ol, ml);

	oneline("print over index");

	print_origin_my_fun("[30]", ol[30], ml[30]);

	twoline("at");

	oneline("print element");

	print_origin_my_fun("at(1)", ol.at(1), ml.at(1));
	print_origin_my_fun("at(20)", ol.at(20), ml.at(20));
	
	oneline("print over index");

	// print_origin_my_fun("at(30)", ol.at(30), ml.at(30));

	twoline("front back");
	print_origin_my_fun("front", ol.front(), ml.front());
	print_origin_my_fun("back", ol.back(), ml.back());
	


}
