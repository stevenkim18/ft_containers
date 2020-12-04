#include <iostream>
#include <stack>
#include "Stack.hpp"

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
void print_origin_my_fun(std::string const &str, T ori_value, T my_value)
{
	std::cout << GREEN <<"ori " << str << " = " << ori_value << RESET;
	std::cout << RED << " my " << str << " = " << my_value << RESET << std::endl;
}

int main(void)
{
	std::stack<int> ost;
	ft::Stack<int> mst;

	twoline("empty");

	std::cout << std::boolalpha;

	print_origin_my_fun("empty", ost.empty(), mst.empty());
	print_origin_my_fun("size", ost.size(), mst.size());

	twoline("push");

	oneline("push 100 to 500");

	for (int i = 1; i <= 5; i++)
	{
		ost.push(i * 100);
		mst.push(i * 100);
	}

	print_origin_my_fun("size", ost.size(), mst.size());

	oneline("top");

	print_origin_my_fun("top", ost.top(), mst.top());

	oneline("pop");

	ost.pop();
	mst.pop();

	print_origin_my_fun("size", ost.size(), mst.size());
	print_origin_my_fun("top", ost.top(), mst.top());

	oneline("pop 3times");

	for (int i = 0; i < 3; i++)
	{
		ost.pop();
		mst.pop();
	}

	print_origin_my_fun("size", ost.size(), mst.size());
	print_origin_my_fun("top", ost.top(), mst.top());

	oneline("pop last");

	ost.pop();
	mst.pop();

	print_origin_my_fun("size", ost.size(), mst.size());
	//print_origin_my_fun("top", ost.top(), mst.top());

}
