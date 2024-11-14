#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& src) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
}

Brain& Brain::operator=(const Brain& src) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &src) {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = src._ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

std::string    Brain::getIdea(size_t i) const {
    if (i < 100) {
        std::cout << "Idea " << i << ": " << _ideas[i] << std::endl;
        return _ideas[i];
    }
    else {
        std::cout << "Brain too small to get idea " << i << std::endl;
        return "";
    }
}

void    Brain::setIdea(size_t i, std::string idea) {
    if (i < 100)
        _ideas[i] = idea;
    else
        std::cout << "Brain too small to set idea " << i << std::endl;
}