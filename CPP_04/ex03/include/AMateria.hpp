#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria {
protected:
    std::string type;
public:
AMateria(const std::string &type);
AMateria(const AMateria &other);
virtual ~AMateria();
const AMateria &operator=(const AMateria &other);

const std::string &getType() const;
virtual AMateria *clone() const = 0;
virtual void use(ICharacter &target);
};

#endif
