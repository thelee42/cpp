#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
    private:
    std::string Lname;
    std::string Fname;
    std::string Nname;
    std::string number;
    std::string Dsecret;

    public:
    void SetContact();
    void PrintContact();
    std::string &GetInfo(std::string info);
};

#endif
