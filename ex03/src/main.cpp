#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
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
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    me->use(2, *bob);
    me->use(4, *bob);
    tmp = src->createMateria("knights of the round table");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->equip(tmp);
    me->use(2, *bob);
    me->use(3, *bob);
    me->unequip(0);

    Character Cloud("Cloud");
    Cloud.use(0, *bob);
    tmp = src->createMateria("cure");
    Cloud.equip(tmp);
    Cloud.use(0, *bob);

    Character Sephiroth("Sephiroth");
    Sephiroth = Cloud;
    Sephiroth.use(0, *bob);
    Sephiroth.use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}