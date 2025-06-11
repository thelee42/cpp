#include "Bureaucrat.hpp"
#include    "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form taxForm("Tax Form", 45, 10);

        bob.signForm(taxForm);  // 실패 (grade 50 > 45)
        Bureaucrat alice("Alice", 40);
        alice.signForm(taxForm); // 성공 (grade 40 <= 45)
    } catch (std::exception& e) {
        std::cout << "Exception caught in main: " << e.what() << std::endl;
    }
    return 0;
}