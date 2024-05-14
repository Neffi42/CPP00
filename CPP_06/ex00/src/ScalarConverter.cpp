#include "ScalarConverter.hpp"
#include <cctype>
#include <cstddef>
#include <iostream>
#include <limits>
#include <string>

enum type {
    typeChar = 1,
    typeInt,
    typeFloat,
    typeDouble,
    typePseudo
};

static bool isChar(const std::string &s) {
    if (s.length() != 1)
        return false;
    if (s.at(0) < std::numeric_limits<char>::min())
        return false;
    if (s.at(0) > std::numeric_limits<char>::max())
        return false;
    if (isdigit(s.at(0)))
        return false;
    return true;
}

static bool isInt(const std::string &s) {
    for (std::size_t i = s.at(0) == '-' ? 1 : 0; i < s.length(); i++) {
        if (!isdigit(s.at(i)))
            return false;
    }
    return true;
}

static bool isFloat(const std::string &s) {
    (void)s;
    return true;
}

static bool isDouble(const std::string &s) {
    (void)s;
    return true;
}

void ScalarConverter::convert(const std::string &s) {
    if (isChar(s)) {

    }
    else if (isInt(s)) {

    }
    else if (isFloat(s)) {

    }
    else if (isDouble(s)) {

    }
    else {
        std::cout << "Undefined type\n";
    }
}
