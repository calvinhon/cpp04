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
        for (int i = 0; i < 100, i++)
            this->_ideas[i] = src._ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}