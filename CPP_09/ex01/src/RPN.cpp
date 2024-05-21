#include "RPN.hpp"
#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>

RPN::RPN() {
    std::cout << "RPN's default constructor called\n";
}

RPN::RPN(std::string s) {
    std::cout << "RPN's param constructor called\n";
    parseInput(s);
}

RPN::RPN(const RPN& other) {
    std::cout << "RPN's copy constructor called\n";
    *this = other;
}

RPN::~RPN() {
    std::cout << "RPN's destructor called\n";
}

const RPN& RPN::operator=(const RPN& other) {
    std::cout << "RPN's copy assignement operator called\n";
    if (this != &other) {
        st = other.st;
    }
    return *this;
}

const char* RPN::WrongInputException::what() const throw() {
    return "Error";
}

static bool checkSpaces(const std::string& s, size_t i) {
    if (i == 0) {
        return (isspace(s[i + 1]));
    }
    else if (i + 1 == s.size()) {
        return (isspace(s[i - 1]));
    }
    return isspace(s[i - 1]) && isspace(s[i + 1]);
}

static bool isOps(char c) {
    std::string opsChar = "+-/*";
    return opsChar.find(c) != std::string::npos;
}

void RPN::parseInput(std::string s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (isspace(s[i])) {
            continue;
        }
        else if (!checkSpaces(s, i)) {
            throw WrongInputException();
        }
        else if (isdigit(s[i]) || isOps(s[i])) {
            st.push(s[i]);
        }
        else {
            throw WrongInputException();
        }
    }
}

char RPN::frontPop() {
    char c = st.front();
    st.pop();
    return c;
}

void RPN::setOp() {
    switch (st.front()) {
        case '+':
            currentOp = PLUS;
            break;
        case '-':
            currentOp = MINUS;
            break;
        case '/':
            currentOp = DIVIDE;
            break;
        case '*':
            currentOp = TIME;
            break;
    }
    st.pop();
}

int RPN::executeOp(int result) {
    char c = frontPop();
    int i;
    if (!isdigit(c) || st.empty()) {
        throw WrongInputException();
    }
    i = c - '0';
    if (isdigit(st.front())) {
        i = executeOp(i);
    }
    setOp();
    switch (currentOp) {
        case PLUS:
            result += i;
            break;
        case MINUS:
            result -= i;
            break;
        case DIVIDE:
            if (i == 0)
                throw WrongInputException();
            result /= i;
            break;
        case TIME:
            result *= i;
            break;
    }
    return result;
}

void RPN::execute() {
    char c;
    int result;

    if (st.empty()) {
        throw WrongInputException();
    }

    c = frontPop();
    if (!isdigit(c)) {
        throw WrongInputException();
    }
    result = c - '0';

    while (!st.empty()) {
        result = executeOp(result);
    }

    std::cout << result << "\n";
}
