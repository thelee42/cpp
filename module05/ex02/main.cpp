#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 140);   // 등급 140 (sign 145 필요)
        Bureaucrat alice("Alice", 50); // 등급 50 (sign 72, exec 45, 25, 5 필요)

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << "\n--- ShrubberyCreationForm ---\n";
        bob.signForm(shrubbery);  // 서명 가능 (140 <= 145)
        bob.executeForm(shrubbery);  // 실행 불가 (140 > 137) → 예외
        alice.executeForm(shrubbery); // 실행 가능 (50 <= 137)

        std::cout << "\n--- RobotomyRequestForm ---\n";
        alice.signForm(robotomy);  // 서명 가능 (50 <= 72)
        alice.executeForm(robotomy); // 실행 가능 (50 <= 45? No -> 예외, 그래서 등급 조절 필요)
        Bureaucrat execRobotomy("ExecRobot", 40); // 등급 40 (exec 45 필요)
        execRobotomy.executeForm(robotomy); // 실행 가능

        std::cout << "\n--- PresidentialPardonForm ---\n";
        Bureaucrat president("President", 1); // 등급 1 (sign 25, exec 5)
        president.signForm(pardon);
        president.executeForm(pardon);

    } catch (std::exception &e) {
        std::cerr << "예외 발생: " << e.what() << std::endl;
    }
    return 0;
}