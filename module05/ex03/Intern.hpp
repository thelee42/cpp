#ifndef Intern_HPP
# define Intern_HPP

#include    <string>
#include    <exception>

class AForm;

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        AForm *makeForm(const std::string &formName, const std::string &target);
    private:
        static AForm *createShrubbery(const std::string& target);
        static AForm *createRobotomy(const std::string& target);
        static AForm *createPresidential(const std::string& target);
};

#endif