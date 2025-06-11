#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

#include    "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        void execute(Bureaucrat const & executor) const;
};

#endif