#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> arr;

	for (int i = 0; i < 10; i++)
		arr.push_back(i);

	std::vector<int>::iterator it = arr.begin();
	std::vector<int>::iterator ite = arr.end();

	// ==
	if (it == ite)
		std::cout << "==" << std::endl;

	// !=
	if (it != ite)
		std::cout << "!=" << std::endl;

	// *
	std::cout << "*it = " << *it << std::endl;

	// ++
	it++;
	std::cout << "*it = " << *it << std::endl;

	// --
	it--;
	std::cout << "*it = " << *it << std::endl;

	

	// *it = 0
	// +(int)
	std::cout << "*(it+7) = " << *(it+7) << std::endl;


}
