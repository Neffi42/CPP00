#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm: public AForm {
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    const RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    void beExecuted() const;
};
