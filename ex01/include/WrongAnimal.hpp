#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class   WrongAnimal {
    
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& src);
    WrongAnimal& operator=(const WrongAnimal& src);
    virtual ~WrongAnimal();

    virtual void        makeSound() const;
    const std::string&  getType() const;

protected:
    std::string _type;

};

#endif