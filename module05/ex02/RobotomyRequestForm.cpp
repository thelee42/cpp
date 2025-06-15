#include    "RobotomyRequestForm.hpp"
#include    <iostream>
#include    <cstdlib>
#include    <ctime>


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("No target") {};

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {};

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void RobotomyRequestForm::executeAction() const {
    std::cout << "Bzzzzzzzzz...\n";
    srand(time(NULL));
    if (rand() % 2) {
        std::cout << _target << " has been robotomized successfully\n";
    }
    else {
        std::cout << "Robotomy failed\n";
    }
}

//srand = seed
//srand(time(NULL)) : renewal seed
//rand : random number int