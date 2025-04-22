#include    <iostream>
#include    <cctype>
#include    <limits>
#include    "contact.hpp"
#include    "phonebook.hpp"

bool is_all_digit(const std::string& str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (!std::isdigit(static_cast<unsigned char>(*it)))
            return false;
    }
    return true;
}

void    Contact::SetContact()
{
	std::string input;
    std::cout << "\n*******************\n"
            << "*ADD a new contact*\n"
            << "*******************\n";
	do {
		std::cout << "First name : ";
		std::getline(std::cin, input);
	} while (input.empty());
	Fname = input;
	do {
		std::cout << "Last name : ";
		std::getline(std::cin, input);
	} while (input.empty());
	Lname = input;
	do {
		std::cout << "Nickname : ";
		std::getline(std::cin, input);
	} while (input.empty());
	Nname = input;
	do {
		std::cout << "Phone number : ";
		std::getline(std::cin, input);
		if (!is_all_digit(input))
			std::cout << "Please enter digits only\n";
	} while (input.empty() || !is_all_digit(input));
	number = input;
	do {
		std::cout << "Darkest secret : ";
		std::getline(std::cin, input);
	} while (input.empty());
	Dsecret = input;
    std::cout << "**A new contact has been registered ! **\n";
}

void    Contact::PrintContact()
{
	
	std::cout << "\n**Here's the contact's information**\n"
			<< "First name : " << Fname << "\n"
    		<< "Last name : " << Lname << "\n"
    		<< "Nickname : " << Nname << "\n"
			<< "Phone number : " << number << "\n"
    		<< "Darkest secret : " << Dsecret << std::endl;
}

std::string &Contact::GetInfo(std::string info)
{
    if (info == "prenom")
        return (Fname);
    else if (info == "nom")
        return (Lname);
    else
        return (Nname);
}


PhoneBook::PhoneBook()
{
    index = 0;
}

void    PhoneBook::AddContact()
{
    contact[index].SetContact();
    index = (index + 1) % 8;
}

std::string    colon_str(std::string &str)
{
    if (str.length() > 10)
        return(str.substr(0, 9) + ".");
    else
        return(str);
}
void    PhoneBook::PrintPhoneBook()
{
	std::cout << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::setw(10) << "First name";
	std::cout << "|";
	std::cout << std::setw(10) << "Last name";
	std::cout << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < index; i++)
    {
        std::cout << std::setw(10) << i + 1;
        std::cout << "|";
        std::cout << std::setw(10) << colon_str(contact[i].GetInfo("prenom"));
        std::cout << "|";
        std::cout << std::setw(10) << colon_str(contact[i].GetInfo("nom"));
        std::cout << "|";
        std::cout << std::setw(10) << colon_str(contact[i].GetInfo("surnom")) << std::endl;
    }
}

void    PhoneBook::SearchContact()
{
    int input;
	std::string input_str;

	std::cout << "\n*********************\n"
			<< "*Your Phonebook list*\n"
			<< "*********************\n";
	if (index == 0)
	{
		std::cout << "No contact in your phonebook\n";
		return ;
	}
	PrintPhoneBook();
    while (1)
    {
        std::cout << "Enter the index to search : ";
        std::getline(std::cin, input_str);
        if (input_str.empty() || !is_all_digit(input_str))
        {
            std::cout << "Please enter a number between 1 and " << index << "\n";
            continue;
        }
        input = std::stoi(input_str);
        if (input < 1 || input > index)
        {
            std::cout << "Please enter a number between 1 and " << index << "\n";
            continue;
        }
        if (input <= index)
            contact[input - 1].PrintContact();
        break;
    }
}

int main()
{
    PhoneBook phonebook = PhoneBook();

    while(1)
    {
        std::cout <<"\n**************************\n"
                << "*Welcome to the PHONEBOOK*\n"
                <<"**************************\n"
                << "*ADD to add a contact\n"
                << "*SEARCH to search a contact\n"
                << "*EXIT to exit\n"
                << "Enter your command : ";
        std::string cmd;
        std::getline(std::cin, cmd);
        while (!(cmd == "ADD" || cmd == "SEARCH" || cmd == "EXIT"))
		{
			std::cout << "Please enter a valid command\nEnter your command : ";
			std::getline(std::cin, cmd);
		}
        if (cmd == "ADD")
            phonebook.AddContact();
        else if (cmd == "SEARCH")
            phonebook.SearchContact();
        else if (cmd == "EXIT")
            return 0;
    }
}

