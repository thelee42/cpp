#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include    "AForm.hpp"
#include    <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        PresidentialPardonForm(const std::string &target);
        void executeAction() const;
};

#endif