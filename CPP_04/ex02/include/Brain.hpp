#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include <cstring>

class Brain {
public:
    std::string ideas[100];
    Brain();
    Brain(const Brain &other);
    Brain(const std::string ideas[100]);
    ~Brain();
    const Brain &operator=(const Brain &other);
};

#endif
