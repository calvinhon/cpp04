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

    void        makeSound() const;
    std::string getIdea(size_t i) const;
    void        setIdea(size_t i, std::string idea);

private:
    Brain*  _brain;

};

#endif