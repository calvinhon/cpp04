#include "dog.hpp"

Dog::Dog(): Animal() {
    std::cout << "Dog default constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& src): Animal(src) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog& Dog::operator=(const Dog& src) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &src) {
        this->_type = src._type;
        this->_brain = src._brain;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

void    Dog::makeSound() const {
    std::cout << "woof woof" << std::endl;
}