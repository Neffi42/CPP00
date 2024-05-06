#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define MAX_SIZE 4

class MateriaSource: public IMateriaSource {
private:
    AMateria *inventory[MAX_SIZE];
    int size;
public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    ~MateriaSource();
    const MateriaSource &operator=(const MateriaSource &other);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif
