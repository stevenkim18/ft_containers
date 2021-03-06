#include <iostream>
#include <map>
#include "Map.hpp"

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

template <typename K, typename T>
void    print_all_element(std::map<K, T> &om, ft::Map<K, T> &mm)
{   
    std::cout << GREEN << "[ ";
    for (typename std::map<K, T>::iterator it = om.begin(); it != om.end(); it++)
        std::cout << "(" << it->first << "," << it->second << ")";
    std::cout << " ]" << RESET << std::endl;

    std::cout << RED << "[ ";
    for (typename ft::Map<K, T>::iterator it = mm.begin(); it != mm.end(); ++it)
        std::cout << "(" << it->_key << "," << it->_value << ")";
    std::cout << " ]" << RESET << std::endl;
}

int main(void)
{
    typedef std::map<int, std::string>::iterator oiterator;
    typedef ft::Map<int, std::string>::iterator miterator;

    std::map<int, std::string> om;
    ft::Map<int, std::string> mm;
    
    std::pair<std::map<int, std::string>::iterator, bool> oipairs;
    std::pair<ft::Map<int, std::string>::iterator, bool> mipairs;

    twoline("empty size");
    oneline("empty map");

    std::cout << std::boolalpha;
    print_ori_my_value("size", om.size(), mm.size());
    print_ori_my_value("empty", om.empty(), mm.empty());

    oneline("insert 1 node");

    om.insert(std::make_pair<int, std::string>(10, "sda"));    
    mm.insert(ft::Pair<int, std::string>(10, "sda")); 

    print_all_element(om, mm);

    print_ori_my_value("size", om.size(), mm.size());
    print_ori_my_value("empty", om.empty(), mm.empty());

    twoline("constructor");

    oneline("insert 2 node in om, mm");

    om.insert(std::make_pair<int, std::string>(30, "zxc"));     mm.insert(ft::Pair<int, std::string>(30, "zxc")); 
    om.insert(std::make_pair<int, std::string>(35, "gfg"));     mm.insert(ft::Pair<int, std::string>(35, "gfg")); 

    print_all_element(om, mm);

    oneline("range constructor");

    std::map<int, std::string> om42(om.begin(), om.end());
    ft::Map<int, std::string> mm42(mm.begin(), mm.end());

    print_all_element(om42, mm42);

    oneline("copy constructor");

    std::map<int, std::string> om44(om);
    ft::Map<int, std::string> mm44(mm);

    print_all_element(om44, mm44);

    twoline("max_size");

    print_ori_my_value("max_size", om.max_size(), mm.max_size());

    twoline("operator []");

    oneline("insert more node");

    om.insert(std::make_pair<int, std::string>(20, "asd"));     mm.insert(ft::Pair<int, std::string>(20, "asd")); 
    om.insert(std::make_pair<int, std::string>(3, "fghn"));     mm.insert(ft::Pair<int, std::string>(3, "fghn")); 
    om.insert(std::make_pair<int, std::string>(17, "vrv"));     mm.insert(ft::Pair<int, std::string>(17, "vrv")); 
    om.insert(std::make_pair<int, std::string>(15, "twer"));    mm.insert(ft::Pair<int, std::string>(15, "twer"));
    om.insert(std::make_pair<int, std::string>(13, "xcvb"));    mm.insert(ft::Pair<int, std::string>(13, "xcvb"));
    om.insert(std::make_pair<int, std::string>(2, "uyj"));      mm.insert(ft::Pair<int, std::string>(2, "uyj"));  
    om.insert(std::make_pair<int, std::string>(10, "wer"));     mm.insert(ft::Pair<int, std::string>(10, "wer")); 
    om.insert(std::make_pair<int, std::string>(8, "xvv"));      mm.insert(ft::Pair<int, std::string>(8, "xvv"));  
    om.insert(std::make_pair<int, std::string>(19, "qwer"));    mm.insert(ft::Pair<int, std::string>(19, "qwer"));
    om.insert(std::make_pair<int, std::string>(4, "dfg"));      mm.insert(ft::Pair<int, std::string>(4, "dfg"));  
    om.insert(std::make_pair<int, std::string>(8, "qwer"));     mm.insert(ft::Pair<int, std::string>(8, "qwer")); 
    om.insert(std::make_pair<int, std::string>(5, "zdf"));      mm.insert(ft::Pair<int, std::string>(5, "zdf"));  
    om.insert(std::make_pair<int, std::string>(1, "yert"));     mm.insert(ft::Pair<int, std::string>(1, "yert")); 
    om.insert(std::make_pair<int, std::string>(11, "zsd"));     mm.insert(ft::Pair<int, std::string>(11, "zsd")); 
    om.insert(std::make_pair<int, std::string>(16, "uti"));     mm.insert(ft::Pair<int, std::string>(16, "uti")); 

    print_all_element(om, mm);
    mm.print_all();

    oneline("key in the map");

    print_ori_my_value("[10]", om[10], mm[10]);
    print_ori_my_value("[20]", om[20], mm[20]);

    oneline("no key in the map");
    print_ori_my_value("size", om.size(), mm.size());
    print_ori_my_value("[100]", om[100], mm[100]);
    print_ori_my_value("size", om.size(), mm.size());
    print_all_element(om, mm);

    oneline("insert value latest key(100)");
    om[100] = "hun";
    mm[100] = "hun";

    print_ori_my_value("[100]", om[100], mm[100]);

    twoline("insert with only value");

    print_all_element(om, mm);
    mm.print_all();

    std::pair<oiterator, bool> oinsert;
    std::pair<miterator, bool> minsert;

    oneline("insert no key in the map");

    oinsert = om.insert(std::make_pair<int, std::string>(42, "fds"));
    minsert = mm.insert(ft::Pair<int, std::string>(42, "fds"));

    print_all_element(om, mm);

    print_ori_my_value("pair iter first", oinsert.first->first, minsert.first->_key);
    print_ori_my_value("pair iter second", oinsert.first->second, minsert.first->_value);
    std::cout << std::boolalpha;
    print_ori_my_value("pair bool", oinsert.second, minsert.second);

    oneline("insert already exist key in the map");

    oinsert = om.insert(std::make_pair<int, std::string>(42, "eiq"));
    minsert = mm.insert(ft::Pair<int, std::string>(42, "eiq"));

    print_all_element(om, mm);

    print_ori_my_value("pair iter first", oinsert.first->first, minsert.first->_key);
    print_ori_my_value("pair iter second", oinsert.first->second, minsert.first->_value);
    print_ori_my_value("pair bool", oinsert.second, minsert.second);

    twoline("insert with iter and value");

    oiterator oiter;
    miterator miter;

    oneline("insert no key in the map");

    oiter = om.insert(om.begin(), std::make_pair<int, std::string>(24, "wfj"));
    miter = mm.insert(mm.begin(), ft::Pair<int, std::string>(24, "wfj"));

    print_all_element(om, mm);

    print_ori_my_value("iter first", oiter->first, miter->_key);
    print_ori_my_value("iter second", oiter->second, miter->_value);

    oneline("insert already exist key in the map");

    oiter = om.insert(om.begin(), std::make_pair<int, std::string>(1, "deq"));
    miter = mm.insert(mm.begin(), ft::Pair<int, std::string>(1, "deq"));

    print_ori_my_value("iter first", oiter->first, miter->_key);
    print_ori_my_value("iter second", oiter->second, miter->_value);

    twoline("insert multiple values");

    typedef std::pair<int, std::string> opair;
    typedef ft::Pair<int, std::string> mpair;

    opair opairs[] = { opair(44, "daq"), opair(45, "vdd"), opair(46, "ebr") };
    mpair mpairs[] = { mpair(44, "daq"), mpair(45, "vdd"), mpair(46, "ebr") };

    om.insert(opairs, opairs + 3);
    mm.insert(mpairs, mpairs + 3);

    print_all_element(om, mm);

    twoline("erase with iterator");

    oneline("erase begin");
    om.erase(om.begin());
    mm.erase(mm.begin());

    print_all_element(om, mm);

    oneline("erase end");
    om.erase(--om.end());
    mm.erase(--mm.end());

    print_all_element(om, mm);

    oneline("erase middle");

    oiter = om.begin();
    miter = mm.begin();

    // move to plus 4    
    oiter++; oiter++; oiter++; oiter++;
    miter++; miter++; miter++; miter++;

    print_ori_my_value("iter first", oiter->first, miter->_key);
    print_ori_my_value("iter second", oiter->second, miter->_value);

    om.erase(oiter);
    mm.erase(miter);

    print_all_element(om, mm);

    twoline("erase with key");

    oneline("erase key in the map");

    print_ori_my_value("erase 3", om.erase(3), mm.erase(3));
    print_ori_my_value("erase 10", om.erase(10), mm.erase(10));
    print_ori_my_value("erase 42", om.erase(42), mm.erase(42));

    print_all_element(om, mm);

    oneline("erase no key in the map");
    print_ori_my_value("erase 3", om.erase(3), mm.erase(3));
    print_ori_my_value("erase 30", om.erase(30), mm.erase(30));
    print_ori_my_value("erase 37", om.erase(37), mm.erase(37));

    print_all_element(om, mm);

    twoline("erase with two iterators");

    oneline("erase begin+1 to end-1");

    om.erase(++om.begin(), --om.end());
    mm.erase(++mm.begin(), --mm.end());

    print_all_element(om, mm);

    twoline("swap");

    std::map<int, std::string> om2;
    ft::Map<int, std::string> mm2;

    om2.insert(std::make_pair<int, std::string>(100, "wer"));  mm2.insert(ft::Pair<int, std::string>(100, "wer")); 
    om2.insert(std::make_pair<int, std::string>(200, "xvv"));   mm2.insert(ft::Pair<int, std::string>(200, "xvv"));  

    std::map<int, std::string> om3;
    ft::Map<int, std::string> mm3;

    om3.insert(std::make_pair<int, std::string>(1, "fda"));   mm3.insert(ft::Pair<int, std::string>(1, "fda")); 
    om3.insert(std::make_pair<int, std::string>(2, "sad"));   mm3.insert(ft::Pair<int, std::string>(2, "sad"));  

    om2.swap(om3);
    mm2.swap(mm3);

    oneline("original map2");
    print_all_element(om2, mm2);

    oneline("new map3(swaped map)");
    print_all_element(om3, mm3);

    twoline("clear");
    om.clear();
    mm.clear();

    oneline("clear and insert one node");   
    om.insert(std::make_pair<int, std::string>(1, "vvs"));     mm.insert(ft::Pair<int, std::string>(1, "vvs")); 

    print_all_element(om, mm);
    
    twoline("key_compare");

    std::map<int, std::string>::key_compare okc = om.key_comp();
    ft::Map<int, std::string>::key_compare mkc = mm.key_comp();

    oneline("compare by key(int)");
    print_ori_my_value("3,5", okc(3, 5), mkc(3, 5));
    print_ori_my_value("3,2", okc(3, 2), mkc(3, 2));

    twoline("value_compare");

    om.insert(std::make_pair<int, std::string>(20, "aaa"));     mm.insert(ft::Pair<int, std::string>(20, "aaa")); 
    om.insert(std::make_pair<int, std::string>(3, "fghn"));     mm.insert(ft::Pair<int, std::string>(3, "fghn")); 
    om.insert(std::make_pair<int, std::string>(17, "vrv"));     mm.insert(ft::Pair<int, std::string>(17, "vrv")); 
    om.insert(std::make_pair<int, std::string>(15, "twer"));    mm.insert(ft::Pair<int, std::string>(15, "twer"));
    om.insert(std::make_pair<int, std::string>(13, "xcvb"));    mm.insert(ft::Pair<int, std::string>(13, "xcvb"));
    om.insert(std::make_pair<int, std::string>(2, "zzz"));      mm.insert(ft::Pair<int, std::string>(2, "zzz"));  
    om.insert(std::make_pair<int, std::string>(10, "wer"));     mm.insert(ft::Pair<int, std::string>(10, "wer")); 
    om.insert(std::make_pair<int, std::string>(8, "xvv"));      mm.insert(ft::Pair<int, std::string>(8, "xvv"));  
    om.insert(std::make_pair<int, std::string>(19, "qwer"));    mm.insert(ft::Pair<int, std::string>(19, "qwer"));
    om.insert(std::make_pair<int, std::string>(4, "dfg"));      mm.insert(ft::Pair<int, std::string>(4, "dfg"));  
    om.insert(std::make_pair<int, std::string>(8, "qwer"));     mm.insert(ft::Pair<int, std::string>(8, "qwer")); 
    om.insert(std::make_pair<int, std::string>(5, "zdf"));      mm.insert(ft::Pair<int, std::string>(5, "zdf"));  

    std::map<int, std::string>::value_compare ovc = om.value_comp();
    ft::Map<int, std::string>::value_compare mvc = mm.value_comp();

    print_ori_my_value("compare begin and begin + 1", ovc(*om.begin(), *(++om.begin())), mvc(*mm.begin(), *(++mm.begin()))); 
    print_ori_my_value("compare begin and end", ovc(*om.begin(), *(--om.end())), mvc(*mm.begin(), *(--mm.end())));    
    
    twoline("find");

    print_all_element(om, mm);

    oneline("find key in the map");
    
    print_ori_my_value("find 10", om.find(10)->second, mm.find(10)->_value);
    print_ori_my_value("find 1", om.find(1)->second, mm.find(1)->_value);
    print_ori_my_value("find 20", om.find(20)->second, mm.find(20)->_value);

    oneline("find no key in the map");
    print_ori_my_value("find 100", om.find(100)->first, mm.find(100)->_key);
    print_ori_my_value("find 100", om.find(100)->second, mm.find(100)->_value);

    twoline("count");

    print_ori_my_value("count 1", om.count(1), mm.count(1));
    print_ori_my_value("count 2", om.count(2), mm.count(2));
    print_ori_my_value("count 3", om.count(3), mm.count(3));
    print_ori_my_value("count 21", om.count(21), mm.count(21));

    twoline("lower_bound");

    print_ori_my_value("lower 3", om.lower_bound(3)->first, mm.lower_bound(3)->_key);
    print_ori_my_value("lower 4", om.lower_bound(4)->first, mm.lower_bound(4)->_key);
    print_ori_my_value("lower 5", om.lower_bound(5)->first, mm.lower_bound(5)->_key);
    print_ori_my_value("lower 6", om.lower_bound(6)->first, mm.lower_bound(6)->_key);
    print_ori_my_value("lower 7", om.lower_bound(7)->first, mm.lower_bound(7)->_key);

    twoline("upper_bound");

    print_ori_my_value("upper 10", om.upper_bound(10)->first, mm.upper_bound(10)->_key);
    print_ori_my_value("upper 11", om.upper_bound(11)->first, mm.upper_bound(11)->_key);
    print_ori_my_value("upper 12", om.upper_bound(12)->first, mm.upper_bound(12)->_key);
    print_ori_my_value("upper 18", om.upper_bound(18)->first, mm.upper_bound(18)->_key);
    print_ori_my_value("upper 19", om.upper_bound(19)->first, mm.upper_bound(19)->_key);


    twoline("equal_range");
    
    print_ori_my_value("equal_range 1 first", om.equal_range(1).first->first, mm.equal_range(1)._key->_key);
    print_ori_my_value("equal_range 1 second", om.equal_range(1).second->first, mm.equal_range(1)._value->_key);

    print_ori_my_value("equal_range 100 first", om.equal_range(100).first->first, mm.equal_range(100)._key->_key);
    print_ori_my_value("equal_range 100 second", om.equal_range(100).second->first, mm.equal_range(100)._value->_key);
    
    
    // std::map<int, std::string>::iterator it;

    // it = om.insert(om.begin(), std::make_pair<int, std::string>(99, "sadf"));
    // std::cout << "it->first = " << it->first << " " << "it->second = " << it->second << std::endl;
    // it = om.insert(om.end(), std::make_pair<int, std::string>(6, "dfe"));
    // std::cout << "it->first = " << it->first << " " << "it->second = " << it->second << std::endl;
    // it = om.insert(om.end(), std::make_pair<int, std::string>(10, "dfe"));
    // std::cout << "it->first = " << it->first << " " << "it->second = " << it->second << std::endl;
    
    // print_all_element(om, mm);
    // print_ori_my_value("iter first", oipairs.first->first, mipairs.first->_key);
    // print_ori_my_value("iter second", oipairs.first->second, mipairs.first->_value);
    // print_ori_my_value("bool", oipairs.second, mipairs.second);

    // oipairs = om.insert(std::make_pair<int, std::string>(10, "fds"));    
    // mipairs = mm.insert(ft::Pair<int, std::string>(10, "fds"));

    // print_ori_my_value("iter first", oipairs.first->first, mipairs.first->_key);
    // print_ori_my_value("iter second", oipairs.first->second, mipairs.first->_value);
    // print_ori_my_value("bool", oipairs.second, mipairs.second);


    // print_all_element(om, mm);

    // ft::Map<int, std::string>::iterator oit = mm.begin();
    // ft::Map<int, std::string>::iterator oit2 = mm.end();

    // std::cout << (oit == oit2) << std::endl;
    
}