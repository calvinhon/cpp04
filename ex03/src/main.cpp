#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void) {
    std::cout << "=========== Standard Test ===========" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << std::endl;

    std::cout << "=========== Additional Test ===========" << std::endl;
    std::cout << std::endl;
    
    std::cout << "< me >" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    me->use(2, *bob);
    me->use(4, *bob);
    tmp = src->createMateria("knights of the round table");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);
    me->use(2, *bob);
    me->use(3, *bob);
    me->unequip(1);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->unequip(2);
    me->unequip(3);
    me->unequip(0);
    me->unequip(4);
    me->use(0, *bob);
    std::cout << std::endl;
    
    std::cout << "< Cloud >" << std::endl;
    Character Cloud("Cloud");
    Cloud.use(0, *me);
    tmp = src->createMateria("cure");
    Cloud.equip(tmp);
    Cloud.use(0, *me);
    std::cout << std::endl;

    std::cout << "< Sephiroth >" << std::endl;
    Character Sephiroth("Sephiroth");
	Sephiroth = Cloud;
    Sephiroth.use(0, Cloud);
    Sephiroth.use(1, Cloud);
    tmp = src->createMateria("ice");
    Sephiroth.equip(tmp);
    Sephiroth.use(1, Cloud);
    Sephiroth.unequip(1);

    delete bob;
    delete me;
    delete src;

    return 0;
}