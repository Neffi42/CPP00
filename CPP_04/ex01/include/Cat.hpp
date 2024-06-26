#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
private:
    Brain *brain;
public:
    Cat();
    Cat(const Cat &other);
    ~Cat();
    const Cat &operator=(const Cat &other);

    void setIdea(std::string idea, int index);
    std::string getIdea(int index);
    void makeSound() const;
};

#endif
