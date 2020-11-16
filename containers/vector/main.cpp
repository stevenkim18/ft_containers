#include "Vector.hpp"
#include <vector>
#include <limits>

# define RED "\033[1;31m"
# define RESET "\033[0m"

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

	// max_size
	print_origin_my_fun("max_size()", ori_v.max_size(), my_v.max_size());

}
