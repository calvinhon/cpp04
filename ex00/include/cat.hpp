#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include <iostream>

class   Cat: public Animal {

public:
    Cat();
    Cat(const Cat& src);
    Cat& operator=(const Cat& src);
    ~Cat();

    void    makeSound() const;

};

#endif