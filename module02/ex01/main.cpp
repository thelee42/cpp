
#include    "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}

/* 고정소수점의 핵심 개념
고정소수점 수는 내부에 정수로 저장하지만, **“어디까지가 정수부고 어디부터가 소수부다”**라는 **규칙(_bits)**에 따라 해석하는 방식이에요.
	•	정수는: 정수값 << _bits 로 고정소수점화
	•	소수는: 소수값 * (1 << _bits) → 정수로 반올림해서 저장
 */