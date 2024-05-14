#pragma once

#include <fstream>
#include <string>
#include <ostream>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
private:
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    void beExecuted() const;
};

#define tree "\n\
                                                         .\n\
                                              .         ;  \n\
                 .              .              ;\%     ;;   \n\
                   ,           ,                :;\%  \%;   \n\
                    :         ;                   :;\%;'     .,   \n\
           ,.        \%;     \%;            ;        \%;'    ,;\n\
             ;       ;\%;  \%\%;        ,     \%;    ;\%;    ,\%'\n\
              \%;       \%;\%;      ,  ;       \%;  ;\%;   ,\%;' \n\
               ;\%;      \%;        ;\%;        \% ;\%;  ,\%;'\n\
                `\%;.     ;\%;     \%;'         `;\%\%;.\%;'\n\
                 `:;\%.    ;\%\%. \%@;        \%; ;@\%;\%'\n\
                    `:\%;.  :;bd\%;          \%;@\%;'\n\
                      `@\%:.  :;\%.         ;@@\%;'   \n\
                        `@\%.  `;@\%.      ;@@\%;         \n\
                          `@\%\%. `@\%\%    ;@@\%;        \n\
                            ;@\%. :@\%\%  \%@@\%;       \n\
                              \%@bd\%\%\%bd\%\%:;     \n\
                                #@\%\%\%\%\%:;;\n\
                                \%@@\%\%\%::;\n\
                                \%@@@\%(o);  . '         \n\
                                \%@@@o\%;:(.,'         \n\
                            `.. \%@@@o\%::;         \n\
                               `)@@@o\%::;         \n\
                                \%@@(o)::;        \n\
                               .\%@@@@\%::;         \n\
                               ;\%@@@@\%::;.          \n\
                              ;\%@@@@\%\%:;;;. \n\
                          ...;\%@@@@@\%\%:;;;;,..\n"
