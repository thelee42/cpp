#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include    <string>
#include    <exception>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other);
        // static bool isCharLitteral(const std::string& literal);
        // static bool isIntLitteral(const std::string& literal);
        // static bool isFloatLitteral(const std::string& literal);
        // static bool isDoubleLitteral(const std::string& literal);
        // static bool isPseudoLitteral(const std::string& literal);
        // static void printChar(char var);
        // static void printInt(int var);
        // static void printFloat(float var);
        // static void printDouble(double var);
    public:
        static void convert(const std::string& literal);
};

#endif

//명시적으로 객체 생성을 막으려면 생성자/소멸자/복사자를 private 에 선언
//**정적 함수(static function)**는 C++에서 객체와 무관하게 클래스 자체에 속하는 함수 
//객체를 만들지 않고도 사용할 수 있는 함수
// 객체없음, *this 포인터 없음


/* 

litteral = 변수에 저장되기 전 값 그 자체

static 고정 메모리 공간 공유 sort_cast<type>(var)
1. static var : 함수를 종료해도 값 유지
2. static methode : 객체 없이 함수 호출. 객체X this 포인터 X
3. static class : 모든 멤버가 static methode, 라이브러리용


casting 
static_cast : 가장 일반적인 캐스팅. 상속관계, 기본형 타입 간 변환에 사용
dynamic_cast : 런타임때 타입체크. 다형성 클래스 간 안전한 다운캐스팅에 사용. virtual 함수 필요
                upcasting - 자식->부모. 캐스팅 필요X
                downcasting - 부모->자식
const_cast : const/volatile 속성을 제거/추가할 때 사용
reinterpret_cast : 비트 단위 reinterpretation. 위험함. 포인터 간 캐스팅 등에 사용
** module06 는 타입변환이므로 static_cast **
*/