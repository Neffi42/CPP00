#pragma once

#include <exception>
#include <map>
#include <string>

#define PATH_TO_DATA "./data.csv"
#define BITCOIN_CREATION_YEAR 2009
#define CURRENT_YEAR 2024
#define SPACES " \t\n\r\f\v"

class BitcoinExchange {
private:
    std::map<std::string, float> m;
    void processData();
    void calculateExchangeRate(std::string date, float& f) const;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    const BitcoinExchange& operator=(const BitcoinExchange& other);

    void processInput(const char* inputFile) const;

    class OpenDataBaseException: public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class InvalidDataBaseException: public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class OpenInputException: public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class InvalidInputFileException: public std::exception {
    public:
        virtual const char* what() const throw();
    };
};
