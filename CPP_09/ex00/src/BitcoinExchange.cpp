#include "BitcoinExchange.hpp"
#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange's default constructor called\n";
    processData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    std::cout << "BitcoinExchange's copy constructor called\n";
    *this = other;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "BitcoinExchange's destructor called\n";
}

const BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    std::cout << "BitcoinExchange's copy assignement operator called\n";
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

static std::string itos(int i) {
    std::stringstream ss;

    ss << i;
    return ss.str();
}

static bool processDateElement(const std::string& s, int lowLimit, int highLimit) {
    char *end = NULL;
    int i = std::strtol(s.c_str(), &end, 10);
    if (*end != '\0') {
        return false;
    }
    if ((s.at(0) == '0' && s.at(1) != i + '0') || (s.at(0) != '0' && s != itos(i))) {
        return false;
    }
    if (i < lowLimit || i > highLimit) {
        return false;
    }
    return true;
}

static bool parseDate(const std::string& s) {
    size_t pos = 0;
    size_t pos2 = 0;
    std::string sub;

    if ((pos = s.find("-")) == std::string::npos) {
        return false;
    }
    if (!processDateElement(s.substr(0, pos++), BITCOIN_CREATION_YEAR, CURRENT_YEAR)) {
        return false;
    }
    if ((pos2 = s.find("-", pos)) == std::string::npos) {
        return false;
    }
    if (!processDateElement(s.substr(pos, pos2++ - pos), 1, 12)) {
        return false;
    }
    if ((pos = s.find("-", pos2)) != std::string::npos) {
        return false;
    }
    if (!processDateElement(s.substr(pos2, s.size() - pos2), 1, 31)) {
        return false;
    }
    return true;
}

void BitcoinExchange::processData() {
    std::ifstream file;
    std::string line;
    std::string date;
    size_t pos = 0;
    char* end = NULL;
    float f = 0;

    file.open(PATH_TO_DATA);
    if (file.bad()) {
        throw OpenDataBaseException();
    }

    std::getline(file, line);
    if (line != "date,exchange_rate") {
        throw InvalidDataBaseException();
    }

    while (file.eof() == false) {
        std::getline(file, line);
        if (line.empty()) {
            continue;
        }
        if ((pos = line.find(",")) == std::string::npos) {
            throw InvalidDataBaseException();
        }
        date = line.substr(0, pos);
        line.erase(0, pos + 1);
        if (date.empty() || line.empty() || parseDate(date) == false) {
            throw InvalidDataBaseException();
        }
        f = strtof(line.c_str(), &end);
        if (errno == ERANGE || *end != '\0') {
            throw InvalidDataBaseException();
        }
        data.insert(std::pair<std::string, float>(date, f));
    }
    if (data.empty()) {
        throw InvalidDataBaseException();
    }
}

void BitcoinExchange::processInput(const char* inputFile) {
    std::ifstream file;
    file.open(inputFile);
    if (file.bad()) {
        throw OpenInputException();
    }
}

const char* BitcoinExchange::OpenDataBaseException::what() const throw() {
    return "Cannot open database file";
}

const char* BitcoinExchange::InvalidDataBaseException::what() const throw() {
    return "Database is invalid";
}

const char* BitcoinExchange::OpenInputException::what() const throw() {
    return "Cannot open input file";
}
