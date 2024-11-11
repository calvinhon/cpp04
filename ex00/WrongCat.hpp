#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class   WrongCat: public WrongAnimal {

public:
    WrongCat();
    WrongCat(const WrongCat& src);
    WrongCat& operator=(const WrongCat& src);
    ~WrongCat();

};

#endif