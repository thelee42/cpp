#include    "Form.hpp"
#include    "Bureaucrat.hpp"
#include    <ostream>

const char* Form::GradeTooHighException::what() const throw() {
    return ("Grade Too High !");
}
const char* Form::GradeTooLowException::what() const throw() {
    return ("Grade Too Low !");
}

Form::~Form() {}

Form::Form(const std::string& Name, int signGrade, int execGrade) : name(Name), sign(false), gradeToSign(signGrade), gradeToExec(execGrade) {

    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    if (signGrade < 1 || execGrade < 1 )
        throw GradeTooHighException();
}

Form::Form(const Form& other) : name(other.name), sign(other.sign), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        sign = other.sign;
    }
    return *this;
}

const std::string& Form::getName() const {
    return name;
}
int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExec() const {
    return gradeToExec;
}

bool Form::getSignStatus() const {
    return sign;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form name : " << form.getName() << "\nGrade to sign : " << form.getGradeToSign()
        << "\nGrade to execute : " << form.getGradeToExec();
    if (form.getSignStatus())
        out <<  "\nThis form is signed\n";
    else
        out << "\nThis form is not signed\n";
    return out;
}


void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    sign = true;
}
