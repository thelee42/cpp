#include    "Bureaucrat.hpp"
#include    "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade Too High !");
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade Too Low !");
}

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string Name, int Grade) : name(Name) {
    if (Grade > 150)
        throw GradeTooLowException();
    if (Grade < 1)
        throw GradeTooHighException();
    grade = Grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        //name = other.getName(); //impossible
        grade = other.grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const {
    return name;
}
int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::imcrementGrade() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}
void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}

void Bureaucrat::signForm(AForm& aform)
{
    try {
        aform.beSigned(*this);
        std::cout << name << " signed " << aform.getName() << std::endl;
    }
    catch(std::exception& e) {
        std::cout << name << " couldn't sign " << aform.getName() << "because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& aform) const {
    try {
        aform.execute(*this);
        std::cout << name << " executed " << aform.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << name << " couldn't execute " << aform.getName() << " because " << e.what() << std::endl;
    }
}