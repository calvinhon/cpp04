#include "dog.hpp"

Dog::Dog(): Animal() {
    std::cout << "Dog default constructor called" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog& src): Animal(src) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog& Dog::operator=(const Dog& src) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const {
    std::cout << "woof woof" << std::endl;
}