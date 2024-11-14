#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    const   Animal* meta = new Animal();
    const   Animal* j = new Dog();
    const   Animal* i = new Cat();

    std::cout << meta->getType() << std::endl;
    meta->makeSound();

    std::cout << i->getType() << std::endl;
    i->makeSound();

    std::cout << j->getType() << std::endl;
    j->makeSound();
    std::cout << std::endl;

    const   WrongAnimal* meta2 = new WrongAnimal();
    const   WrongAnimal* i2 = new WrongCat();

    std::cout << meta2->getType() << std::endl;
    meta2->makeSound();

    std::cout << i2->getType() << std::endl;
    i2->makeSound();
    std::cout << std::endl;

    delete meta;
    delete j;
    delete i;
    delete meta2;
    delete i2;

    return 0;
}