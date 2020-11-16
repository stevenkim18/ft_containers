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
