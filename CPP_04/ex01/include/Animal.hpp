#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const std::string &type);
    Animal(const Animal &other);
    virtual ~Animal();

    const Animal &operator=(const Animal &other);

    const std::string &getType() const;
    virtual void makeSound() const;
};

#endif
