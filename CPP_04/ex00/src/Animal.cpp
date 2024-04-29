#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &other);
    ~Animal();
    const Animal &operator=(const Animal &other);
};

#endif
