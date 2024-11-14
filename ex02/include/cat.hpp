#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include <iostream>
#include "Brain.hpp"

class   Cat: public Animal {

public:
    Cat();
    Cat(const Cat& src);
    Cat& operator=(const Cat& src);
    ~Cat();

    void        makeSound() const;
    std::string getIdea(size_t i) const;
    void        setIdea(size_t i, std::string idea);

private:
    Brain*  _brain;

};

#endif