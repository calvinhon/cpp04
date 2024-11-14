#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    std::cout << "============ Animal Array ============" << std::endl;
    int     animal_count = 4;
    const   Animal* meta[animal_count];
    // Animal  test;

    for (int i = 0; i < animal_count; i++) {
        if (i < animal_count / 2)
            meta[i] = new Dog();
        else
            meta[i] = new Cat();
    }
    std::cout << std::endl;

    for (int i = 0; i < animal_count; i++) {
        std::cout << meta[i]->getType() << std::endl;
        meta[i]->makeSound();
        std::cout << std::endl;
    }

    for (int i = 0; i < animal_count; i++)
        delete meta[i];
    std::cout << std::endl;

    std::cout << "============ Deep Copy ============" << std::endl;
    std::cout << std::endl;
    std::cout << "< Original >" << std::endl;
    Dog basic;
    for (int j = 0; j < 101; j++)
        basic.setIdea(j, "eat, sleep, play, repeat");
    for (int j = 0; j < 101; j++)
        basic.getIdea(j);
    std::cout << std::endl;

    std::cout << "< Copy >" << std::endl;
    Dog tmp = basic;
    for (int j = 0; j < 103; j++)
        tmp.getIdea(j);
    std::cout << std::endl;

    return 0;
}