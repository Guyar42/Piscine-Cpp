#include "../includes/dog.hpp"
#include "../includes/animal.hpp"


Dog::Dog(): Animal() {
    std::cout << "Constructor default Dog called" << std::endl;
    this->_name = "Dog"; 
}

Dog::~Dog() {
    std::cout << "Destructor default Dog called" << std::endl;
}

Dog::Dog(Dog const & src) {
    std::cout << "Copy Constructor Dog called" << std::endl;
    *this = src;
    return;
}

Dog & Dog::operator=(Dog const & rhs) {
   (void) rhs;
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "who let the dogs out ? woof woof woof" << std::endl;
}