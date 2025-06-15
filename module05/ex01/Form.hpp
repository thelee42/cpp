#ifndef Form_HPP
# define Form_HPP

#include    <string>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool    sign;
        const int gradeToSign;
        const int gradeToExec;
        Form();
    public:
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        Form(const std::string& name, int signGrade, int execGrade); //string : const + &
        const std::string& getName() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        bool getSignStatus() const;
        void beSigned(Bureaucrat &bureaucrat);
        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif