#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria {
public:
    Ice();
    Ice(const Ice &other);
    ~Ice();
    const Ice &operator=(const Ice &other);

    Ice *clone() const;
    void use(ICharacter &target);
};
#endif
