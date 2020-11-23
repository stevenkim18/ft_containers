#include <iostream>
#include <vector>
#include "Vector.hpp"

int main(void)
{
	std::vector<int> v;
	ft::Vector<int> myv;

	v.insert(v.begin(), 100);
	myv.insert(myv.begin(), 100);

	std::vector<int>::iterator it = v.insert(v.begin(), 10);
	ft::Vector<int>::iterator myit = myv.insert(myv.begin(), 10);

	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	std::cout << "size = " << v.size() << " cap = " << v.capacity() << std::endl;
	std::cout << "*it = " << *it << std::endl;


	for (int i = 0; i < myv.size(); i++)
		std::cout << myv[i] << " ";
	std::cout << std::endl;
	std::cout << "size = " << myv.size() << " cap = " << myv.capacity() << std::endl;
	std::cout << "*myit = " << *myit << std::endl;

}
