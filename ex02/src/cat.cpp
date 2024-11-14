#include "cat.hpp"

Cat::Cat(): Animal() {
    std::cout << "Cat default constructor called" << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& src): Animal(src) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->_type = src._type;
    this->_brain = new Brain(*src._brain);
}

Cat& Cat::operator=(const Cat& src) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &src) {
        this->_type = src._type;
        delete this->_brain;
        this->_brain = new Brain(*src._brain);
    }
    return *this;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound() const {
    std::cout << "meow meow" << std::endl;
}

std::string    Cat::getIdea(size_t i) const {
    return _brain->Brain::getIdea(i);
}

void    Cat::setIdea(size_t i, std::string idea) {
    _brain->Brain::setIdea(i, idea);
}