#include "cat.hpp"

Cat::Cat(): Animal() {
    std::cout << "Cat default constructor called" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat& src): Animal(src) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat& Cat::operator=(const Cat& src) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound() const {
    std::cout << "meow meow" << std::endl;
}