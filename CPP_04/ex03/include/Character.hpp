#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"

# define MAX_SIZE 4

class Character: public ICharacter {
private:
    std::string name;
    AMateria *inventory[MAX_SIZE];
    int size;
public:
    Character(std::string name);
    Character(Character &other);
    ~Character();
    const Character &operator=(Character &other);

    const std::string &getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
