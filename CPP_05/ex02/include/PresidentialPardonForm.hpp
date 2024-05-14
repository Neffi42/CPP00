#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm: public AForm {
private:
    std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    const PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    void beExecuted() const;
};
