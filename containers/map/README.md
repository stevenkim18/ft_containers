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


