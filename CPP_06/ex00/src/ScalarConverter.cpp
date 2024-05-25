#include "ScalarConverter.hpp"
#include <cstdlib>
#include <ctype.h>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <limits>
#include <string>
#include <sys/errno.h>

static bool isChar(values &val) {
    if (val.s.length() != 1)
        return false;
    if (val.s.at(0) < std::numeric_limits<char>::min())
        return false;
    if (val.s.at(0) > std::numeric_limits<char>::max())
        return false;
    if (isprint(val.s.at(0)) == false)
        return false;
    if (isdigit(val.s.at(0)))
        return false;
    val.c = val.s.at(0);
    val.type = CHAR;
    val.cFlag = OK;
    return true;
}

static bool isInt(values &val) {
    char *end;

    if ((val.s.at(0) != '-' && val.s.length() > 10) || (val.s.at(0) == '-' && val.s.length() > 11))
        return false;
    for (size_t i = val.s.at(0) == '-' ? 1 : 0; i < val.s.length(); i++) {
        if (!isdigit(val.s.at(i)))
            return false;
    }
    val.i = strtol(val.s.c_str(), &end, 10);
    if (*end != '\0' || val.i > std::numeric_limits<int>::max() || val.i < std::numeric_limits<int>::min()) {
        val.i = 0;
        return false;
    }
    val.type = INT;
    val.iFlag = OK;
    return true;
}

static bool isFloat(values &val) {
    char *end;

    if (val.s.find('.') == std::string::npos)
        return false;
    if (val.s.find('f') == std::string::npos)
        return false;
    val.f = strtof(val.s.c_str(), &end);
    if (errno == ERANGE || *end != 'f' || *(end + 1) != '\0') {
        val.f = 0;
        return false;
    }
    val.type = FLOAT;
    return true;
}

static bool isDouble(values &val) {
    char *end;

    if (val.s.find('.') == std::string::npos)
        return false;
    val.d = strtod(val.s.c_str(), &end);
    if (errno == ERANGE || *end != '\0') {
        val.d = 0;
        return false;
    }
    val.type = DOUBLE;
    return true;
}

static bool isPseudo(values &val) {
    if (val.s == "-inff" || val.s == "+inff" || val.s == "-inf" || val.s == "+inf" || val.s == "nan") {
        val.type = PSEUDO;
        return true;
    }
    return false;
}

static void convertChar(values &val) {
    val.i = val.c;
    val.f = val.c;
    val.d = val.c;
}

static void convertInt(values &val) {
    if (val.i <= std::numeric_limits<char>::max() && val.i >= std::numeric_limits<char>::min()) {
        val.cFlag = OK;
        val.c = val.i;
    }
    val.f = val.i;
    val.d = val.i;
}

static void convertFloat(values &val) {
    if (val.f <= std::numeric_limits<char>::max() && val.f >= std::numeric_limits<char>::min()) {
        val.cFlag = OK;
        val.c = val.f;
    }
    if (val.f <= std::numeric_limits<int>::max() && val.f >= std::numeric_limits<int>::min()) {
        val.iFlag = OK;
        val.i = val.f;
    }
    val.d = val.f;
}

static void convertDouble(values &val) {
    if (val.d > std::numeric_limits<char>::max() && val.d < std::numeric_limits<char>::min())
        val.c = IMPOSSIBLE;
    else
        val.c = val.d;
    if (val.d > std::numeric_limits<int>::max() && val.d < std::numeric_limits<int>::min())
        val.i = std::numeric_limits<int>::max() + 1;
    else
        val.i = val.d;
    if (val.d <= std::numeric_limits<float>::max() && val.d >= std::numeric_limits<float>::min()) {
        val.type = FLOAT;
        val.f = val.d;
    }
}

static void convertPseudo(values &val) {
    val.c = IMPOSSIBLE;
    val.i = std::numeric_limits<int>::max() + 1;
    if (val.s == "nan") {
        val.f = std::numeric_limits<float>::quiet_NaN();
        val.d = std::numeric_limits<double>::quiet_NaN();
    }
    else if (val.s == "+inf" || val.s == "+inff") {
        val.f = std::numeric_limits<float>::infinity();
        val.d = std::numeric_limits<double>::infinity();
    }
    else if (val.s == "-inf" || val.s == "-inff") {
        val.f = std::numeric_limits<float>::infinity() * -1;
        val.d = std::numeric_limits<double>::infinity() * -1;
    }
}

static void printConvert(values &val) {
    std::cout << "char: ";
    if (val.cFlag == IMPOSSIBLE)
        std::cout << "impossible\n";
    else if (!isprint(val.c))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << val.c << "'\n";

    std::cout << "int: ";
    if (val.iFlag == IMPOSSIBLE)
        std::cout << "impossible\n";
    else
        std::cout << val.i << "\n";

    std::cout << "float: ";
    if (val.type == DOUBLE)
        std::cout << "impossible\n";
    else if (val.f - static_cast<long long>(val.f) == 0.0)
        std::cout << val.f << ".0f\n";
    else
        std::cout << val.f << "f\n";

    std::cout << "double: ";
    if (val.type == PSEUDO || val.d - static_cast<long long>(val.d) != 0.0)
        std::cout << val.d << "\n";
    else
        std::cout << val.d << ".0\n";
}

void ScalarConverter::convert(const std::string &s) {
    values val = {s, 0, IMPOSSIBLE, 0, IMPOSSIBLE, 0, 0, 0};

    if (isChar(val) || isInt(val) || isFloat(val) || isDouble(val) || isPseudo(val)) {
        switch (val.type) {
            case CHAR:
                convertChar(val);
                break;
            case INT:
                convertInt(val);
                break;
            case FLOAT:
                convertFloat(val);
                break;
            case DOUBLE:
                convertDouble(val);
                break;
            case PSEUDO:
                convertPseudo(val);
                break;
            default:
                std::cerr << "Oh that's not suppose to happend...\n";
                break;
        }
        printConvert(val);
    }
    else {
        std::cerr << "Undefined type\n";
    }
}
