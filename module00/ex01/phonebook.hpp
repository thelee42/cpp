#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include    <iomanip>
#include    "contact.hpp"

class PhoneBook
{
    private:
    Contact contact[8];
    int index;

    public:
    PhoneBook();
    void AddContact();
    void PrintPhoneBook();
    void SearchContact();
};

#endif