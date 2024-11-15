#include "Character.hpp"

Character::Character(): _name("Nameless") {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    _head = addNode();
}

Character::Character(std::string const name): _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    _head = addNode();
}

Character::Character(const Character& src): _name(src._name) {
    for (int i = 0; i < 4; i++) {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
    copyLlist(src._head, this->_head);
}

Character& Character::operator=(const Character& src) {
    if (this != &src) {
        _name = src._name;
        for (int i = 0; i < 4; i++) {
            if (_inventory[i]) {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (src._inventory[i])
                _inventory[i] = src._inventory[i]->clone();
        }
        while (_head) {
            _unequipped_inv* tmp = _head->next;
            if (_head->m)
                delete _head->m;
            delete _head;
            _head = tmp;
        }
        copyLlist(src._head, this->_head);
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete _inventory[i];
    }
    while (_head) {
        _unequipped_inv* tmp = _head->next;
        if (_head->m)
            delete _head->m;
        delete _head;
        _head = tmp;
    }
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) {
        std::cout << getName() << " failed to equip unknown materia" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
		if (_inventory[i] == m) {
			std::cout << m->getType() << " materia already equipped in slot " << i << std::endl;
			return ;
		}
	}
    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            std::cout << getName() << " equipped slot " << i << ": " << _inventory[i]->getType() << std::endl;
            return ;
        }
    }
    std::cout << getName() << " could not equip " << m->getType() << " materia because inventory is full" << std::endl;
    for (int i = 0; i < 4; i++) {
		if (_inventory[i] == m)
			return ;
	}
	delete m;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid slot " << idx << " for " << getName() << " to unequip" << std::endl;
        return ;
    }
    if (!_inventory[idx]) {
        std::cout << "No materia in slot " << idx << " for " << getName() << " to unequip" << std::endl;
        return ;
    }
    std::cout << getName() << " unequipped slot " << idx << ": " << _inventory[idx]->getType() << std::endl;
    _unequipped_inv* cur = _head;
    while (cur->m)
        cur = cur->next;
    cur->m = _inventory[idx];
    cur->next = addNode();
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid slot " << idx << " for " << getName() << " to use" << std::endl;
        return ;
    }
    if (!_inventory[idx]) {
        std::cout << "No materia in slot " << idx << " for " << getName() << " to use" << std::endl;
        return ;
    }
    _inventory[idx]->use(target);
}

_unequipped_inv* addNode() {
    _unequipped_inv* node = new _unequipped_inv;
    node->m = NULL;
    node->next = NULL;
    return node;
}

void copyLlist(_unequipped_inv* src, _unequipped_inv*& cpy) {
    cpy = addNode();
	_unequipped_inv* cur = cpy;
    while (src) {
        if (src->m) {
            cur->m = src->m->clone();
            cur->next = addNode();
            cur = cur->next;
        }
        src = src->next;
    }
}