#include "ScalarConverter.hpp"
#include <cstdlib>
#include <ctype.h>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

static int myStoi(const std::string &s) {
    int x = 0;
    std::istringstream(s) >> x;
    return x;
}

static std::string itos(int x) {
    std::stringstream ss;

    ss << x;
    std::string str = ss.str();
    return str;
}

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
    for (size_t i = s.at(0) == '-' ? 1 : 0; i < s.length(); i++) {
        if (!isdigit(s.at(i)))
            return false;
    }
    return s == itos(myStoi(s));
}

static bool isFloat(const std::string &s) {
    bool pointFound = false;
    int mantissa = 0;

    for (size_t i = 0; i < s.length(); i++) {
        if (i == s.length() -1) {
            if (s.at(i) != 'f')
                return false;
        }
        else if (!isdigit(s.at(i))) {
            if (pointFound == false && s.at(i) == '.')
                pointFound = true;
            else
                return false;
        }
        else if (pointFound) {
            mantissa++;
            if (mantissa > 7)
                return false;
        }
    }
    return pointFound && mantissa > 0;
}

static bool isDouble(const std::string &s) {
    bool pointFound = false;
    int mantissa = 0;

    for (size_t i = 0; i < s.length(); i++) {
        if (!isdigit(s.at(i))) {
            if (pointFound == false && s.at(i) == '.')
                pointFound = true;
            else
                return false;
        }
        else if (pointFound) {
            mantissa++;
            if (mantissa > 15)
                return false;
        }
    }
    return pointFound && mantissa > 0;
}

static bool isPseudo(const std::string &s) {
    if (s == "-inff" || s == "+inff" || s == "-inf" || s == "+inf" || s == "nan")
        return true;
    return false;
}

void ScalarConverter::convert(const std::string &s) {
    if (isChar(s)) {
        std::cout << "Char type\n";
    }
    else if (isInt(s)) {
        std::cout << "Int type\n";
    }
    else if (isFloat(s)) {
        std::cout << "Float type\n";
    }
    else if (isDouble(s)) {
        std::cout << "Double type\n";
        std::cout << std::atof(s.c_str()) << "\n";
    }
    else if (isPseudo(s)) {
        std::cout << "Pseudo type\n";
    }
    else {
        std::cout << "Undefined type\n";
    }
}
