#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
    for (int i = 0; i < 4; i++) {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
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

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        if (_inventory[i])
            delete _inventory[i];
}

void    MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++)
        if (!_inventory[i]) {
            _inventory[i] = m;
            return ;
        }
    std::cout << "MateriaSource can't hold more than 4 materia" << std::endl;
    delete m;
}

AMateria*   MateriaSource::createMateria(std::string const & type) {
    if (type == "ice")
        return new Ice();
    else if (type == "cure")
        return new Cure();
    else
        return 0;
}