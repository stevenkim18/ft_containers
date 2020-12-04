#include <iostream>
#include <queue>
#include "Queue.hpp"

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
	std::queue<int> oqu;
	ft::Queue<int> mqu;

	twoline("empty");

	std::cout << std::boolalpha;

	print_origin_my_fun("empty", oqu.empty(), mqu.empty());
	print_origin_my_fun("size", oqu.size(), mqu.size());

	twoline("push");

	oneline("push 100 to 500");

	for (int i = 1; i <= 5; i++)
	{
		oqu.push(i * 100);
		mqu.push(i * 100);
	}

	print_origin_my_fun("size", oqu.size(), mqu.size());
	print_origin_my_fun("front", oqu.front(), mqu.front());
	print_origin_my_fun("back", oqu.back(), mqu.back());

	twoline("pop");

	oqu.pop();
	mqu.pop();

	print_origin_my_fun("size", oqu.size(), mqu.size());
	print_origin_my_fun("front", oqu.front(), mqu.front());
	print_origin_my_fun("back", oqu.back(), mqu.back());

	oneline("pop 3time");

	for (int i = 0; i < 3; i++)
	{
		oqu.pop();
		mqu.pop();
	}

	print_origin_my_fun("size", oqu.size(), mqu.size());
	print_origin_my_fun("front", oqu.front(), mqu.front());
	print_origin_my_fun("back", oqu.back(), mqu.back());

	oneline("pop and empty");

	oqu.pop();
	mqu.pop();
}
