#ifndef easyfind_HPP
# define easyfind_HPP

#include <algorithm> // std::find
#include <iterator>
#include <exception>

class NotFoundException : public std::exception {
    public:
        const char *what() const throw() {
            return "Value not found";
        }
};

template <typename T>
typename T::iterator easyfind(T &container, const int &value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if(it == container.end())
        throw NotFoundException();
    return it;
}

#endif


/* 
STL : standard template library

1. container : stockage et gestion de data (vector, list, map, set, stack, queue)
2. algorithm : traitement de data (sort, find, copy, transform)
3. iterator : acces à data (begin(), end(), rbegin(), rend())

STL의 사용 예시
1. 벡터를 사용하여 동적 배열 구현
2. 리스트를 사용하여 연결 리스트 구현
3. 맵을 사용하여 키-값 쌍 저장

STL의 장점
1. 재사용성
2. 효율성
3. 일관성

STL의 단점
1. 복잡성
2. 성능 문제 (특히 작은 데이터에 대해서는 오버헤드가 발생할 수 있음)
3. 디버깅 어려움

STL을 사용하지 않는 이유
1. 성능 최적화가 필요한 경우
2. 특정한 요구사항이 있는 경우 (예: 메모리 관리)
3. STL이 제공하지 않는 기능이 필요한 경우

STL을 사용하는 이유
1. 코드의 간결함과 가독성 향상
2. 시간 절약 (이미 구현된 알고리즘과 자료구조를 사용할 수 있음)
3. 유지보수 용이성

--------------

Nested type 중첩타입 : type defined within another type.
typename T::iterator를 사용하는 이유:
    T가 벡터, 리스트, 덱 등 다양한 컨테이너일 수 있으므로, 해당 컨테이너의 iterator 타입을 반환해야 함

*/