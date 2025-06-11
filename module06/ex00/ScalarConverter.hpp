#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include    <string>

class ScalarConverter
{
    public:
        static void convert(const std::string& literral);
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other);
};

#endif

//명시적으로 객체 생성을 막으려면 생성자/소멸자/복사자를 private 에 선언
//**정적 함수(static function)**는 C++에서 객체와 무관하게 클래스 자체에 속하는 함수 
//객체를 만들지 않고도 사용할 수 있는 함수
// 객체없은, *this 포인터 없음