#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    Bureaucrat bob("Bob", 50);
    Form taxForm("Tax Form", 45, 10);

    std::cout << bob;
    std::cout << taxForm;

    bob.signForm(taxForm);  // cannot sign: Bob grade 50 > 45

    Bureaucrat alice("Alice", 40);
    std::cout << alice;
    alice.signForm(taxForm); // can sign: Alice grade 40 < 45

    std::cout << taxForm;

    return 0;
}