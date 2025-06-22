#include    "Intern.hpp"
#include    <iostream>
#include    "AForm.hpp"
#include    "ShrubberyCreationForm.hpp"
#include    "PresidentialPardonForm.hpp"
#include    "RobotomyRequestForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

AForm *Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string formnames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm* (*formes[3])(const std::string&) = {createShrubbery, createRobotomy, createPresidential};
    for(int i = 0; i < 3; i++) {
        if(formnames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formes[i](target);
        }
    }
    std::cerr << "Form doesn't exist" << std::endl;
    return NULL;
}

//일반 함수 포인터: AForm* (*)(std::string)
//멤버 함수 포인터: AForm* (Intern::*)(std::string)