#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
    std::cout << "WrongCat default constructor called" << std::endl;
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src): WrongAnimal(src) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
}

WrongCat& WrongCat::operator=(const WrongCat& src) {
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}