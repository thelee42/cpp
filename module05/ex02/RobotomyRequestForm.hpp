#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include    "AForm.hpp"
#include    <string>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        RobotomyRequestForm(const std::string &target);
        void executeAction() const;
};

#endif