#include "Character.hpp"

Character::Character(): _name("Nameless") {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    _head = new _unequipped_inv;
    _head->m = 0;
    _head->next = NULL;
}

Character::Character(std::string name): _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    _head = new _unequipped_inv;
    _head->m = 0;
    _head->next = NULL;
}

Character::Character(const Character& src) {
    for (int i = 0; i < 4; i++)
        if (this->_inventory[i])
            delete _inventory[i];
    for (int i = 0; i < 4; i++) {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& src) {
    if (this != &src) {
        for (int i = 0; i < 4; i++) 
            if (this->_inventory[i])
                delete _inventory[i];
        for (int i = 0; i < 4; i++) {
            if (src._inventory[i])
                this->_inventory[i] = src._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) 
        if (_inventory[i])
            delete _inventory[i];
    while (_head) {
        _unequipped_inv* tmp = _head->next;
        delete _head;
        _head = tmp;
    }
}

std::string const& Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m)
        std::cout << getName() << " failed to equip unknown materia" << std::endl;
    else {
        for (int i = 0; i < 4; i++)
            if (!_inventory[i]) {
                _inventory[i] = m;
                std::cout << getName() << " equipped slot " << i << ": " << _inventory[i]->getType() << std::endl;
                return ;
            }
        std::cout << getName() << " could not equip " << m->getType() << " materia because inventory is full" << std::endl;
    }
}

void Character::unequip(int idx) {
    if (idx > -1 && idx < 4) {
        if (_inventory[idx]) {
            while (_head->m)
                _head->m = _inventory[idx];
            else {
                // _unequipped_inv* cur = _head;
                while (_head->next)
                    _head = _head->next;
                _head->next = new _unequipped_inv;
                _head = _head->next;
                _head->m = _inventory[idx];
                _head->next = NULL;
            }
            _inventory[idx] = NULL;
            std::cout << getName() << " unequipped slot " << idx << ": " << _inventory[idx]->getType() << std::endl;
        }
        else
            std::cout << "No materia in slot " << idx << "for" << getName() << " to unequip" << std::endl;
    }
    if (idx < 0 || idx > 3)
        std::cout << "Can't unequip, inventory has max 4 items" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
    if (idx > -1 && idx < 4) {
        if (_inventory[idx])
            _inventory[idx]->use(target);
        else
        std::cout << "No materia in slot " << idx << " for " << getName() << " to use" << std::endl;
    }
    else
        std::cout << "Invalid slot " << idx << " for " << getName() << " to use" << std::endl;
}