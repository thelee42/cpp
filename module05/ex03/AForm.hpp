#ifndef Form_HPP
# define Form_HPP

#include    <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool    sign;
        const int gradeToSign;
        const int gradeToExec;
        AForm();
    protected:
        virtual void executeAction() const = 0;
    public:
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        AForm(const std::string& name, int signGrade, int execGrade);
        const std::string& getName() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        bool getSignStatus() const;
        void beSigned(Bureaucrat &bureaucrat);
        void execute(Bureaucrat const & executor) const;
        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
        public:
            const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& aform);

#endif