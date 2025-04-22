#include    <string>
#include    <iostream>

int main()
{
    std::string str("HI THIS IS BRAIN");
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "*Memory Addresses*" << std::endl;
    std::cout << "Address of string     : " << &str << std::endl;
    std::cout << "Address held by PTR   : " << stringPTR << std::endl;
    std::cout << "Address held by REF   : " << &stringREF << std::endl;

    std::cout << "*String Values*" << std::endl;
    std::cout << "Value of string       : " << str << std::endl;
    std::cout << "Value pointed by PTR  : " << *stringPTR << std::endl;
    std::cout << "Value pointed by REF  : " << stringREF << std::endl;
}