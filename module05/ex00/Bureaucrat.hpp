#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include    <string>
#include    <exception>
#include    <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        Bureaucrat(); // defaut constructor forbidden
    public:
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
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif

// 사용자 정의 exception class : what 메소드의 문구 정의
// ex)
// class GradeTooHighException : public std::exception {
// public:
//     const char* what() const throw() {
//         return "Grade too high!";
//     }
// };