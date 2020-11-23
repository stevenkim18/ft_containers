## max_size()
- https://en.cppreference.com/w/cpp/types/numeric_limits/max
- size_t의 최대 값에서 int의 크기(4byte)를 나눠야 함.

## reserve(size_type n)
- 메모리만 n 만큼 할당 함.
- 현재 할당 되어 있는 메모리 크기 보다 n이 작으면 아무런 작동 안함.

## front(), back()
- vector 안에 아무런 값이 없었을 때 세그폴트!

## pop_back()
- 마지막 원소를 제거
- vector가 비어 있을 때 undefined behaviour
https://www.geeksforgeeks.org/vectorpush_back-vectorpop_back-c-stl/


# iterator
## ++a, a++
- 일반 변수의 전위 후위 연산자 처럼 작동
~~~c
// 대입 먼저
b = a++ -> b = a -> a += 1

// 증가 먼저
b = ++a -> a += 1 -> b = a
~~~
- 그래서 후위 연산자에서는 복사 생성자로 만든 새로운은 iterator를 리턴 함

## const와 non const iterator의 차이
- const는 iterator가 가르키는 값을 변경 할 수 없습니다.
~~~c++
*const_iter = 1; (X)
~~~
