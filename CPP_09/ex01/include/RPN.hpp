#pragma once

#include <exception>
#include <queue>
#include <string>

enum {
    PLUS = 1,
    MINUS,
    DIVIDE,
    TIME
} ops;

class RPN {
private:
    std::queue<char> st;
    int currentOp;
    void parseInput(std::string s);
    char frontPop();
    void setOp();
    int executeOp(int i);
public:
    RPN();
    RPN(std::string s);
    RPN(const RPN& other);
    ~RPN();

    const RPN& operator=(const RPN& other);

    void execute();

    class WrongInputException: public std::exception {
        virtual const char* what() const throw();
    };
};
