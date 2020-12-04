#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	// // constructor
	// std::map<std::string, std::string> m;

	// m["key"] = "value";

	// std::cout << m["key"] << std::endl;
	// std::cout << m.size() << std::endl;
	// std::cout << m["hello"] << std::endl;
	// std::cout << m.size() << std::endl;

	// m["hello"] = "world";

	// std::cout << m["hello"] << std::endl;
	// std::cout << m.size() << std::endl;

	// std::cout << "==================" << std::endl;

	// std::map<int, int> im;

	// im[1] = 1;

	// std::cout << im[1] << std::endl;
	// std::cout << im[2] << std::endl;
	// std::cout << im.size() << std::endl;

	map<int, string> m;
	m[1] = "value";

	cout << "m[1] = " << m[1] << endl;
	cout << "size = " << m.size() << endl;

	cout << "m[2] = " << m[2] << endl;
	cout << "size = " << m.size() << endl;
}
