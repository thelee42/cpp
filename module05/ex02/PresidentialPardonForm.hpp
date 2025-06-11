#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include    "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        void executeAction() const;
};

#endif