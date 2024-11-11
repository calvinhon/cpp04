#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"
#include <iostream>
#include "Brain.hpp"

class   Dog: public Animal {

public:
    Dog();
    Dog(const Dog& src);
    Dog& operator=(const Dog& src);
    ~Dog();

    void    makeSound() const;

private:
    Brain*  _brain;

};

#endif