#include "../includes/bureaucrat.hpp"
#include "../includes/error.hpp"



Bureaucrat::Bureaucrat() {
    std::cout << "Constructor default Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int i) {
    if (i <= 1)
        throw Error("Bureaucrat::GradeTooHighException");
    else if (i >= 150)
        throw Error("Bureaucrat::GradeTooLowException");
    else
    {
        this->_name = name;
        this->_grade = i;
    }
    std::cout << "Constructor default Bureaucrat called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor default Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
    std::cout << "Copy Constructor Bureaucrat called" << std::endl;
    *this = src;
    return;
} //

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
    this->_name = rhs._name;
    this->_grade = rhs._grade;
    return *this;
} //


std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::upGrade() {
    if (this->_grade >= 2)
        this->_grade--;
    else
        throw Error("Bureaucrat::GradeTooHighException");
    return;
}

void Bureaucrat::downGrade() {
    if (this->_grade <= 149)
        this->_grade++;
    else
        throw Error("Bureaucrat::GradeTooLowException");
    return;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const & b) {
    out << b.getName() << " bureaucrate grade " << b.getGrade() << std::endl;
    return out;
}