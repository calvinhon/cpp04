#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

struct  _unequipped_inv {
    AMateria*           m;
    _unequipped_inv*    next;
};

_unequipped_inv*    addNode();

class   Character: public ICharacter {

public:
    Character();
    Character(std::string name);
    Character(const Character& src);
    Character& operator=(const Character& src);
    ~Character();

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

private:
    std::string         _name;
    AMateria*           _inventory[4];
    _unequipped_inv*    _head;

};

#endif