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

	ol.reserve(10);
	ml.reserve(10);

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

	print_origin_my_fun("[11]", ol[11], ml[11]);

	twoline("at");

	oneline("print element");

	print_origin_my_fun("at(1)", ol.at(1), ml.at(1));
	print_origin_my_fun("at(20)", ol.at(20), ml.at(20));

	oneline("print over index");

	// print_origin_my_fun("at(30)", ol.at(30), ml.at(30));

	twoline("front back");
	print_origin_my_fun("front", ol.front(), ml.front());
	print_origin_my_fun("back", ol.back(), ml.back());

	twoline("assign");

	oneline("input iterator");

	int arr2[] = {42, 42, 42, 18, 18};

	ol.assign(arr2, arr2 + 5);
	ml.assign(arr2, arr2 + 5);

	print_both_vector(ol, ml);

	oneline("size and value");

	ol.assign(10u, 42);
	ml.assign(10u, 42);

	print_both_vector(ol, ml);

	twoline("pop_back");

	oneline("2 time");

	ol.pop_back();
	ol.pop_back();
	ml.pop_back();
	ml.pop_back();

	print_both_vector(ol, ml);

	twoline("insert");
	ol.clear();
	ml.clear();

	for (int i = 1; i < 6; i++)
	{
		ol.push_back(i);
		ml.push_back(i);
	}

	print_both_vector(ol, ml);

	oneline("insert one value in begin");

	ol.insert(ol.begin(), 42);
	ml.insert(ml.begin(), 42);

	print_both_vector(ol, ml);

	oneline("insert one value in end");

	ol.insert(ol.end(), 42);
	ml.insert(ml.end(), 42);

	print_both_vector(ol, ml);

	oneline("insert one value in middle");

	ol.insert(ol.begin() + 3, 4242);
	ml.insert(ml.begin() + 3, 4242);

	print_both_vector(ol, ml);

	oneline("insert size and values");

	ol.insert(ol.begin() + 1, 5u, 10);
	ml.insert(ml.begin() + 1, 5u, 10);

	print_both_vector(ol, ml);

	oneline("insert by two inputiterator");

	int arr3[] = {100, 100, 100};

	ol.insert(ol.begin() + 3, arr3, arr3 + 3);
	ml.insert(ml.begin() + 3, arr3, arr3 + 3);

	print_both_vector(ol, ml);

	twoline("erase");

	oneline("erase by two iterator");

	ol.erase(ol.begin() + 2, ol.end() - 4);
	ml.erase(ml.begin() + 2, ml.end() - 4);

	print_both_vector(ol, ml);

	oneline("erase by one iterator");

	ol.erase(ol.begin() + 1);
	ml.erase(ml.begin() + 1);

	print_both_vector(ol, ml);

	twoline("swap");

	print_both_vector(ol, ml);
	print_both_vector(fill_ol, fill_ml);

	ol.swap(fill_ol);
	ml.swap(fill_ml);

	oneline("after swap");

	print_both_vector(ol, ml);
	print_both_vector(fill_ol, fill_ml);

	twoline("clear");

	ol.clear();
	ml.clear();

	print_both_vector(ol, ml);

	twoline("== != < <= > >=");

	fill_ol.clear();
	fill_ml.clear();

	for (int i = 1; i < 6; i++)
	{
		ol.push_back(i);
		fill_ol.push_back(i);
		ml.push_back(i);
		fill_ml.push_back(i);
	}

	print_both_vector(ol, ml);
	print_both_vector(fill_ol, fill_ml);

	oneline("same vectors");
	print_origin_my_fun("'=='", ol == fill_ol, ml == fill_ml);
	print_origin_my_fun("'!='", ol != fill_ol, ml != fill_ml);
	print_origin_my_fun("'<'", ol < fill_ol, ml < fill_ml);
	print_origin_my_fun("'<='", ol <= fill_ol, ml <= fill_ml);
	print_origin_my_fun("'>'", ol > fill_ol, ml > fill_ml);
	print_origin_my_fun("'>='", ol >= fill_ol, ml >= fill_ml);

	oneline("diff size");

	ol.pop_back();
	ml.pop_back();

	print_both_vector(ol, ml);
	print_both_vector(fill_ol, fill_ml);

	print_origin_my_fun("'=='", ol == fill_ol, ml == fill_ml);
	print_origin_my_fun("'!='", ol != fill_ol, ml != fill_ml);
	print_origin_my_fun("'<'", ol < fill_ol, ml < fill_ml);
	print_origin_my_fun("'<='", ol <= fill_ol, ml <= fill_ml);
	print_origin_my_fun("'>'", ol > fill_ol, ml > fill_ml);
	print_origin_my_fun("'>='", ol >= fill_ol, ml >= fill_ml);

	oneline("same size smaller element");

	ol.push_back(1);
	ml.push_back(1);

	print_both_vector(ol, ml);
	print_both_vector(fill_ol, fill_ml);

	print_origin_my_fun("'=='", ol == fill_ol, ml == fill_ml);
	print_origin_my_fun("'!='", ol != fill_ol, ml != fill_ml);
	print_origin_my_fun("'<'", ol < fill_ol, ml < fill_ml);
	print_origin_my_fun("'<='", ol <= fill_ol, ml <= fill_ml);
	print_origin_my_fun("'>'", ol > fill_ol, ml > fill_ml);
	print_origin_my_fun("'>='", ol >= fill_ol, ml >= fill_ml);

	twoline("        ");

	twoline("iterator");

	std::vector<int>::iterator oit = ol.begin();
	ft::Vector<int>::iterator mit = ml.begin();

	std::vector<int>::iterator o2it = ol.begin();
	ft::Vector<int>::iterator m2it = ml.begin();

	print_both_vector(ol, ml);
	print_origin_my_fun("it", *oit, *mit);
	print_origin_my_fun("2it", *o2it, *m2it);

	twoline("== != < <= > >=");

	oneline("same iterator");

	print_origin_my_fun("'=='", oit == o2it, mit == m2it);
	print_origin_my_fun("'!='", oit != o2it, mit != m2it);
	print_origin_my_fun("'<'", oit < o2it, mit < m2it);
	print_origin_my_fun("'<='", oit <= o2it, mit <= m2it);
	print_origin_my_fun("'>'", oit > o2it, mit > m2it);
	print_origin_my_fun("'>='", oit >= o2it, mit >= m2it);

	oneline("diff iterator");

	oit++;
	mit++;

	print_origin_my_fun("it", *oit, *mit);
	print_origin_my_fun("2it", *o2it, *m2it);

	print_origin_my_fun("'=='", oit == o2it, mit == m2it);
	print_origin_my_fun("'!='", oit != o2it, mit != m2it);
	print_origin_my_fun("'<'", oit < o2it, mit < m2it);
	print_origin_my_fun("'<='", oit <= o2it, mit <= m2it);
	print_origin_my_fun("'>'", oit > o2it, mit > m2it);
	print_origin_my_fun("'>='", oit >= o2it, mit >= m2it);

	twoline("++");

	oneline("postfix");

	o2it = ++oit;
	m2it = ++mit;

	print_origin_my_fun("it", *oit, *mit);
	print_origin_my_fun("2it", *o2it, *m2it);

	oneline("prefix");

	o2it = oit++;
	m2it = mit++;

	print_origin_my_fun("it", *oit, *mit);
	print_origin_my_fun("2it", *o2it, *m2it);

	twoline("--");

	oneline("postfix");

	o2it = --oit;
	m2it = --mit;

	print_origin_my_fun("it", *oit, *mit);
	print_origin_my_fun("2it", *o2it, *m2it);

	oneline("prefix");

	o2it = oit--;
	m2it = mit--;

	print_origin_my_fun("it", *oit, *mit);
	print_origin_my_fun("2it", *o2it, *m2it);

	twoline("+n -n");

	print_both_vector(ol, ml);

	oneline("+n");

	print_origin_my_fun("begin + 1", *(ol.begin() + 1), *(ml.begin() + 1));

	oneline("-n");

	print_origin_my_fun("end - 3", *(ol.end() - 3), *(ml.end() - 3));

	twoline("+= -=");

	print_origin_my_fun("it", *oit, *mit);

	oneline("+=");

	oit += 2;
	mit += 2;

	print_origin_my_fun("it", *oit, *mit);

	oneline("-=");

	oit -= 3;
	mit -= 3;

	print_origin_my_fun("it", *oit, *mit);

	twoline("[]");

	print_origin_my_fun("it[0]", oit[0], mit[0]);
	print_origin_my_fun("it[1]", oit[1], mit[1]);
	print_origin_my_fun("it[3]", oit[3], mit[3]);

	twoline("                ");

	twoline("reverse_iterator");

	ol[4] = 5;
	ml[4] = 5;

	print_both_vector(ol, ml);

	oneline("rbegin rend");

	print_origin_my_fun("rbegin", *ol.rbegin(), *ml.rbegin());
	print_origin_my_fun("rend - 1", *(ol.rend() - 1), *(ml.rend() - 1));

	twoline("++ --");

	std::vector<int>::reverse_iterator orit = ol.rbegin();
	ft::Vector<int>::reverse_iterator mrit = ml.rbegin();

	oneline("++");

	orit++;
	mrit++;

	print_origin_my_fun("rit", *orit, *mrit);

	oneline("--");

	orit--;
	mrit--;

	print_origin_my_fun("rit", *orit, *mrit);

	twoline("[]");

	print_origin_my_fun("rit[0]", orit[0], mrit[0]);
	print_origin_my_fun("rit[1]", orit[1], mrit[1]);
	print_origin_my_fun("rit[2]", orit[2], mrit[2]);

	twoline("== != < <= > >=");

	std::vector<int>::reverse_iterator o2rit = ol.rbegin() + 2;
	ft::Vector<int>::reverse_iterator m2rit = ml.rbegin() + 2;

	print_origin_my_fun("rit", *orit, *mrit);
	print_origin_my_fun("2rit", *o2rit, *m2rit);

	print_origin_my_fun("'=='", orit == o2rit, mrit == m2rit);
	print_origin_my_fun("'!='", orit != o2rit, mrit != m2rit);
	print_origin_my_fun("'<'", orit < o2rit, mrit < m2rit);
	print_origin_my_fun("'<='", orit <= o2rit, mrit <= m2rit);
	print_origin_my_fun("'>'", orit > o2rit, mrit > m2rit);
	print_origin_my_fun("'>='", orit >= o2rit, mrit >= m2rit);
}
