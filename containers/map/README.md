# map
## map에서 value 값은 없고 key 값만 넣었을 때
~~~c++
map<int, string> m;

m[1] = "value";

cout << "m[1] = " << m[1] << endl;
cout << "size = " << m.size() << endl;

cout << "m[2] = " << m[2] << endl;
cout << "size = " << m.size() << endl;
~~~
~~~
m[1] = value
size = 1
m[2] =
size = 2
~~~
- operator[]로 key 값만 선언해도 각 타입의 defalut 값이 들어감 (string->"", int -> 0)


# 대박 링크
https://medium.com/swlh/binary-search-trees-c-484377f0d349

# 이슈
## BST의 typename T를 std::pair로 받아오려고 했는데 key 값이 중복되면 안되기에 수정해야 함.