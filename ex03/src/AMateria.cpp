#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const& type): _type(type) {}

AMateria::AMateria(const AMateria& src) {
    *this = src;
}

AMateria& AMateria::operator=(const AMateria& src) {
    if (this != &src)
        this->_type = src._type;
    return *this;
}

AMateria::~AMateria() {}

std::string const&  AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    std::string target_name = target.getName();
    std::cout << "Nothing happens to " << target_name << std::endl;
}