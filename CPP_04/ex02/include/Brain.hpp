#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define MAX_IDEA 100

class Brain {
public:
    std::string ideas[MAX_IDEA];
    Brain();
    Brain(const Brain &other);
    Brain(const std::string ideas[MAX_IDEA]);
    ~Brain();
    const Brain &operator=(const Brain &other);
};

#endif
