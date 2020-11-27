#include <iostream>
#include <list>
#include "List.hpp"

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
void    print_ori_my_value(std::string const &str, T ori, T my)
{
    std::cout << GREEN << "ori " << str << " = " << ori << RESET << " ";
    std::cout << RED <<" my " << str << " = " << my << RESET << std::endl;
}

template <typename T>
void    print_all_element(std::list<T> &ol, ft::List<T> &ml)
{   
    std::cout << GREEN << "[ ";
    for (typename std::list<T>::iterator it = ol.begin(); it != ol.end(); it++)
        std::cout << *it << " ";
    std::cout << "]" << RESET << " ";

    std::cout << RED << "[ ";
    for (typename ft::List<T>::iterator it = ml.begin(); it != ml.end(); ++it)
        std::cout << *it << " ";
    std::cout << "]" << RESET << std::endl;
}

bool    over_100(const int& val) { return (val >= 100); }

int main(void)
{
    std::list<int> ol;
    ft::List<int> ml;

    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("front", ol.front(), ml.front());
    print_ori_my_value("back", ol.back(), ml.back());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());
    print_ori_my_value("*rbegin()", *ol.rbegin(), *ml.rbegin());
    print_ori_my_value("*rend()", *ol.rend(), *ml.rend());


    std::cout << "-------------------------------------------" << std::endl;

    ol.push_back(100);
    ml.push_back(100);

    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("front", ol.front(), ml.front());
    print_ori_my_value("back", ol.back(), ml.back());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());
    print_ori_my_value("*rbegin()", *ol.rbegin(), *ml.rbegin());
    print_ori_my_value("*rend()", *ol.rend(), *ml.rend());

    std::cout << "-------------------------------------------" << std::endl;

    ol.push_back(2);
    ml.push_back(2);

    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("front", ol.front(), ml.front());
    print_ori_my_value("back", ol.back(), ml.back());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());
    print_ori_my_value("*rbegin()", *ol.rbegin(), *ml.rbegin());
    print_ori_my_value("*rend()", *ol.rend(), *ml.rend());

    std::cout << "-------------------------------------------" << std::endl;

    ol.push_back(3);
    ml.push_back(3);

    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("front", ol.front(), ml.front());
    print_ori_my_value("back", ol.back(), ml.back());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());
    print_ori_my_value("*rbegin()", *ol.rbegin(), *ml.rbegin());
    print_ori_my_value("*rend()", *ol.rend(), *ml.rend());

    print_all_element(ol, ml);

    std::cout << "-------------------------------------------" << std::endl;

    ol.pop_back();
    ml.pop_back();
    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());
    print_ori_my_value("*rbegin()", *ol.rbegin(), *ml.rbegin());
    print_ori_my_value("*rend()", *ol.rend(), *ml.rend());

    std::cout << "-------------------------------------------" << std::endl;

    ol.pop_back();
    ml.pop_back();
    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());
    print_ori_my_value("*rbegin()", *ol.rbegin(), *ml.rbegin());
    print_ori_my_value("*rend()", *ol.rend(), *ml.rend());

    std::cout << "-------------------------------------------" << std::endl;

    ol.pop_back();
    ml.pop_back();
    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());
    print_ori_my_value("*rbegin()", *ol.rbegin(), *ml.rbegin());
    print_ori_my_value("*rend()", *ol.rend(), *ml.rend());

    std::cout << "-------------------------------------------" << std::endl;

    print_ori_my_value("max_size", ol.max_size(), ml.max_size());

    std::cout << "-------------------------------------------" << std::endl;

    ol.push_front(3);
    ml.push_front(3);
    print_ori_my_value("size", ol.size(), ml.size());
    print_ori_my_value("*begin()", *ol.begin(), *ml.begin());
    print_ori_my_value("*end()", *ol.end(), *ml.end());
    print_ori_my_value("*rbegin()", *ol.rbegin(), *ml.rbegin());
    print_ori_my_value("*rend()", *ol.rend(), *ml.rend());

    // std::list<std::string> ool;
    // ft::List<std::string> mml;

    // print_ori_my_value("size", ool.size(), mml.size());
    // print_ori_my_value("*begin()", *ool.begin(), *mml.begin());
    // print_ori_my_value("*end()", *ool.end(), *mml.end());
    // print_ori_my_value("*rbegin()", *ool.rbegin(), *mml.rbegin());
    // print_ori_my_value("*rend()", *ool.rend(), *mml.rend());

    // std::cout << "-----------------------------------------------" << std::endl;

    // ool.push_back("11"); ool.push_back("22"); ool.push_back("33");
    // mml.push_back("11"); mml.push_back("22"); mml.push_back("33");
    // print_ori_my_value("size", ool.size(), mml.size());
    // print_ori_my_value("*begin()", *ool.begin(), *mml.begin());
    // // std::cout << "end = " << *ool.end() << std::endl;
    // print_ori_my_value("*end()", *ool.end(), *mml.end());
    // print_ori_my_value("*rbegin()", *ool.rbegin(), *mml.rbegin());
    // print_ori_my_value("*rend()", *ool.rend(), *mml.rend());

    twoline("insert");

    ol.push_back(1); ol.push_back(2);
    ml.push_back(1), ml.push_back(2);

    print_all_element(ol, ml);

    std::list<int>::iterator oit = ol.insert(ol.begin(), 10);
    ft::List<int>::iterator mit = ml.insert(ml.begin(), 10);

    oneline("insert to begin");

    print_all_element(ol, ml);
    print_ori_my_value("insert begin", *oit, *mit);

    oneline("insert to end");

    oit = ol.insert(ol.end(), 1000);
    mit = ml.insert(ml.end(), 1000);
    print_all_element(ol, ml);
    print_ori_my_value("insert end", *oit, *mit);

    oneline("insert to begin + 1");

    oit = ol.insert(++ol.begin(), 9999);
    mit = ml.insert(++ml.begin(), 9999);
    print_all_element(ol, ml);
    print_ori_my_value("insert ++begin", *oit, *mit);

    oneline("insert 9 in begin + 1 5times");
    ol.insert(++ol.begin(), 5u, 9);
    ml.insert(++ml.begin(), 5u, 9);
    print_all_element(ol, ml);

    oneline("insert with two iterator");
    oit = ol.end();
    mit = ml.end();
    for (int i = 0; i < 3; i++)
    {
        oit--;
        mit--;
    }
    // insert (1 2 100) to begin + 1
    ol.insert(++ol.begin(), oit, ol.end());
    ml.insert(++ml.begin(), mit, ml.end());
    print_all_element(ol, ml);

    twoline("erase");

    oneline("erase begin");
    oit = ol.erase(ol.begin());
    mit = ml.erase(ml.begin());

    print_ori_my_value("*it", *oit, *mit);
    print_all_element(ol, ml);

    oneline("erase begin + 1 to end");
    oit = ol.erase(++ol.begin(), ol.end());
    mit = ml.erase(++ml.begin(), ml.end());

    print_ori_my_value("*it", *oit, *mit);
    print_all_element(ol, ml);

    twoline("resize");
    oneline("resize to 10");
    ol.resize(10);
    ml.resize(10);

    print_all_element(ol, ml);

    oneline("resize to 20 by 100");
    ol.resize(20, 100);
    ml.resize(20, 100);

    print_all_element(ol, ml);

    oneline("resize to 3");
    ol.resize(3);
    ml.resize(3);

    print_all_element(ol, ml);

    twoline("clear");

    ol.clear();
    ml.clear();

    print_all_element(ol, ml);

    twoline("splice");

    std::list<int> o2l;
    ft::List<int> m2l;

    for (int i = 1; i < 6; i++)
    {
        ol.push_back(i);
        ml.push_back(i);
        o2l.push_back(i * 100);
        m2l.push_back(i * 100);
    }
    
    print_all_element(ol, ml);
    print_all_element(o2l, m2l);

    oneline("splice begin + 1 to other list element");

    ol.splice(++ol.begin(), o2l);
    ml.splice(++ml.begin(), m2l);

    print_all_element(ol, ml);
    print_all_element(o2l, m2l);

    oneline("splice other list one element");
    ol.splice(o2l.begin(), ol, ++ol.begin());
    ml.splice(m2l.begin(), ml, ++ml.begin());

    print_all_element(ol, ml);
    print_all_element(o2l, m2l);

    oneline("splice begin+1 end-1 element to other list");
    ol.splice(o2l.begin(), ol, ++ol.begin(), --ol.end());
    ml.splice(m2l.begin(), ml, ++ml.begin(), --ml.end());

    print_all_element(ol, ml);
    print_all_element(o2l, m2l);

    twoline("remove");

    oneline("remove 500");
    print_all_element(o2l, m2l);

    o2l.remove(500);
    m2l.remove(500);

    print_all_element(o2l, m2l);

    oneline("remove 5");
    ol.push_back(5);
    ml.push_back(5);

    print_all_element(ol, ml);

    ol.remove(5);
    ml.remove(5);

    print_all_element(ol, ml);

    twoline("remove if");
    
    print_all_element(o2l, m2l);
    o2l.remove_if(over_100);
    m2l.remove_if(over_100);

    print_all_element(o2l, m2l);
    
}