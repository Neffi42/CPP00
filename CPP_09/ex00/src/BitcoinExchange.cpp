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
        m = other.m;
    }
    return *this;
}

static void trim(std::string& str)
{
    str.erase(str.find_last_not_of(SPACES)+1);         //suffixing spaces
    str.erase(0, str.find_first_not_of(SPACES));       //prefixing spaces
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
        trim(date);
        trim(line);
        if (date.empty() || line.empty() || parseDate(date) == false) {
            throw InvalidDataBaseException();
        }
        f = strtof(line.c_str(), &end);
        if (errno == ERANGE || *end != '\0') {
            throw InvalidDataBaseException();
        }
        m.insert(std::pair<std::string, float>(date, f));
    }
    if (m.empty()) {
        throw InvalidDataBaseException();
    }
}

void BitcoinExchange::processInput(const char* inputFile) const {
    std::ifstream file;
    std::string line;
    std::string date;
    std::string dup;
    size_t pos = 0;
    char* end = NULL;
    float f = 0;

    file.open(inputFile);
    if (file.bad()) {
        throw OpenInputException();
    }

    std::getline(file, line);
    if (line != "date | value") {
        throw InvalidInputFileException();
    }

    while (file.eof() == false) {
        std::getline(file, line);
        if (line.empty()) {
            continue;
        }
        dup = line;
        if ((pos = line.find("|")) == std::string::npos) {
            std::cerr << "Error: bad input => " << dup << "\n";
            continue;
        }
        date = line.substr(0, pos);
        line.erase(0, pos + 1);
        trim(date);
        trim(line);
        if (date.empty() || line.empty()) {
            std::cerr << "Error: bad input => " << dup << "\n";
            continue;
        }
        else if (parseDate(date) == false) {
            std::cerr << "Error: bad input => " << date << "\n";
            continue;
        }
        f = strtof(line.c_str(), &end);
        if (errno == ERANGE || *end != '\0' || f > 1000) {
            std::cerr << "Error: too large a number.\n";
            continue;
        }
        else if (f <= 0) {
            std::cerr << "Error: not a positive number\n";
            continue;
        }
        calculateExchangeRate(date, f);
    }
}

void BitcoinExchange::calculateExchangeRate(std::string date, float& f) const {
    std::map<std::string, float>::const_iterator low =  m.lower_bound(date);
    if (low == m.begin()) {
        std::cerr << "Error: no data for input => " << date << "\n";
    }
    else {
        low--;
        std::cout << low->first << " => " << f << " = " << low->second * f << "\n";
    }
}

const char* BitcoinExchange::OpenDataBaseException::what() const throw() {
    return "Error: could not open database file.";
}

const char* BitcoinExchange::InvalidDataBaseException::what() const throw() {
    return "Error: database is invalid";
}

const char* BitcoinExchange::OpenInputException::what() const throw() {
    return "Error: could not open input file.";
}

const char* BitcoinExchange::InvalidInputFileException::what() const throw() {
    return "Error: input file is invalid";
}
