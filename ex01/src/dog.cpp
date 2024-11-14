#include "dog.hpp"

Dog::Dog(): Animal() {
    std::cout << "Dog default constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& src): Animal(src) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type = src._type;
    this->_brain = new Brain(*src._brain);
}

Dog& Dog::operator=(const Dog& src) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &src) {
        this->_type = src._type;
        delete this->_brain;
        this->_brain = new Brain(*src._brain);
    }
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const {
    std::cout << "woof woof" << std::endl;
}

std::string    Dog::getIdea(size_t i) const {
    return _brain->Brain::getIdea(i);
}

void    Dog::setIdea(size_t i, std::string idea) {
    _brain->Brain::setIdea(i, idea);
}