#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

#include    "AForm.hpp"
#include    <string>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ShrubberyCreationForm(const std::string &target);
        void executeAction() const;
};

#endif