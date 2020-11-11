# 반복자(iterator)
## 반복자의 개념
- 반복자는 컨테이너에 저장된 원소를 순회하고 접근하는 일반화된 방법을 제공
- 컨테이너와 알고리즘이 하나로 동작하게 묶어주는 인터페이스 역활을 함.
- 반복자 덕에 알고리즘은 특정 컨테이너에 종속적이지 않고 독립적이고 언제든지 컨테이너와 결합하고 동작할 수 있음.

## 반복자의 연산자
- *연산으로 컨테이너 내부의 운소를 가리키고 접근 가능
- ++, --, == 등 연산자 제공

## 반복자의 범주
- 양방향 반복자 : 순방향 반복자(++) 기능에 역방향(--)이 가능한 반복자 (list, set, mulitset, map, multimap)
- 임의 접근 반복자 : 양방향 반복자 기능에 +, -, +=, -=, [] 연산이 가능한 반복자 (vector, deque)
- 모든 컨테이너는 양방향 반복자 이상을 제공함

출처:https://hyeonstorage.tistory.com/318

## 반복자 자료들
- http://www.cplusplus.com/reference/iterator/
### 반복자의 종류들이 잘 설명되어 있음
- https://mayple.tistory.com/entry/CSTL2%EC%9E%A5-%EB%B0%98%EB%B3%B5%EC%9E%90iterator

# 할당자(allocator)
## 할당자의 개념
- https://woo-dev.tistory.com/51

## vector에 커스텀 할당자 만들기
- https://www.youtube.com/watch?v=v-qePUHf8iU&ab_channel=CodesBay

