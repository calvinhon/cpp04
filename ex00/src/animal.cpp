#include "animal.hpp"

Animal::Animal(): _type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& src) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal& Animal::operator=(const Animal& src) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

void    Animal::makeSound() const {
    std::cout << "ifjeavmieamvmqpkdsfvmieafw" << std::endl;
}

const std::string&    Animal::getType() const {
    return _type;
}