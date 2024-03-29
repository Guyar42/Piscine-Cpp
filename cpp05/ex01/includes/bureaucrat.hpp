#pragma once

#include <string>
#include <iostream>
#include "../includes/form.hpp"

class Form;

class Bureaucrat {

public:
    Bureaucrat(std::string name, int i);
    Bureaucrat(Bureaucrat const & src);
    virtual ~Bureaucrat();
    Bureaucrat & operator=(Bureaucrat const & rhs);

    void signForm(Form & f);

    std::string getName() const;
    int getGrade() const;
    void upGrade();
    void downGrade();

    class GradeTooHighException: public std::exception {
        virtual const char * what() const throw();
    };
    class GradeTooLowException: public std::exception {
        virtual const char * what() const throw();
    };

private:
    Bureaucrat();

protected:
    std::string const _name;
    int _grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const & b);