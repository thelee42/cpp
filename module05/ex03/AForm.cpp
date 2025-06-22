#include    "AForm.hpp"
#include    "Bureaucrat.hpp"
#include    <ostream>

const char* AForm::GradeTooHighException::what() const throw() {
    return ("Grade Too High !");
}
const char* AForm::GradeTooLowException::what() const throw() {
    return ("Grade Too Low !");
}
const char* AForm::FormNotSignedException::what() const throw() {
    return ("Form need to be signed first");
}

AForm::~AForm() {}

AForm::AForm(const std::string& Name, int signGrade, int execGrade) : name(Name), sign(false), gradeToSign(signGrade), gradeToExec(execGrade) {

    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    if (signGrade < 1 || execGrade < 1 )
        throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : name(other.name), sign(other.sign), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        sign = other.getSignStatus();
    }
    return *this;
}

const std::string& AForm::getName() const {
    return name;
}
int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExec() const {
    return gradeToExec;
}

bool AForm::getSignStatus() const {
    return sign;
}

std::ostream& operator<<(std::ostream& out, const AForm& aform) {
    out << "Form name : " << aform.getName() << "\nGrade to sign : " << aform.getGradeToSign()
        << "\nGrade to execute : " << aform.getGradeToExec();
    if (aform.getSignStatus())
        out <<  "\nThis form is signed\n";
    else
        out << "\nThis form is not signed\n";
    return out;
}


void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    sign = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (this->getSignStatus() == false)
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExec())
        throw GradeTooLowException();
    executeAction();
}
