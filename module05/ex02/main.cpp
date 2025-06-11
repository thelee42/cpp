#include    "Bureaucrat.hpp"
#include    "AForm.hpp"
#include    <iostream>
#include    "PresidentialPardonForm.hpp"
#include    "ShrubberyCreationForm.hpp"
#include    "RobotomyRequestForm.hpp"

int main() {
    Bureaucrat bob("Bob", 1);

    ShrubberyCreationForm shrub("Home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    try {
        shrub.beSigned(bob);
        shrub.execute(bob);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        robot.beSigned(bob);
        robot.execute(bob);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        pardon.beSigned(bob);
        pardon.execute(bob);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}