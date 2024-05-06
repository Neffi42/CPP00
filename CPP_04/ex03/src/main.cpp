#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int    main() {
    IMateriaSource *src = new MateriaSource();
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();
    src->learnMateria(ice);
    src->learnMateria(cure);
    delete ice;
    delete cure;

    ICharacter *alice = new Character("alice");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    alice->equip(tmp);
    tmp = src->createMateria("cure");
    alice->equip(tmp);
    alice->unequip(1);
    delete tmp;
    tmp = src->createMateria("cure");
    alice->equip(tmp);

    ICharacter *bob = new Character("bob");

    alice->use(0, *bob);
    alice->use(1, *bob);

    delete bob;
    delete alice;
    delete src;

    return (0);
}
