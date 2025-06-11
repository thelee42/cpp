#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include    <string>
#include    <exception>
#include    <iostream>

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        Bureaucrat(const std::string Name, int Grade);
        const std::string& getName() const;
        int getGrade() const;
        void imcrementGrade();
        void decrementGrade();
        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
        };
        void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif