#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"


int main() {
    Intern intern;

    // 1. Valid form names
    AForm* shrub = intern.makeForm("shrubbery creation", "garden");
    AForm* robot = intern.makeForm("robotomy request", "Bender");
    AForm* pardon = intern.makeForm("presidential pardon", "Marvin");

    std::cout << std::endl;

    // 2. Use the forms (sign + execute)
    Bureaucrat bob("Bob", 1);  // 최고 등급 bureaucrat
    if (shrub) {
        bob.signForm(*shrub);
        bob.executeForm(*shrub);
        delete shrub;
    }
    if (robot) {
        bob.signForm(*robot);
        bob.executeForm(*robot);
        delete robot;
    }
    if (pardon) {
        bob.signForm(*pardon);
        bob.executeForm(*pardon);
        delete pardon;
    }

    std::cout << std::endl;

    // 3. Invalid form name
    AForm* unknown = intern.makeForm("invalid form name", "Nobody");
    if (!unknown)
        std::cout << "Received nullptr for unknown form (expected)." << std::endl;

    return 0;
}