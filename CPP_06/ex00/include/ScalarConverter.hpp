#pragma once

#include <string>

#define IMPOSSIBLE false
#define OK true

enum {
    CHAR = 1,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO
};

typedef struct {
    const std::string &s;
    char c;
    bool cFlag;
    int i;
    bool iFlag;
    float f;
    double d;
    int type;
} values;

class ScalarConverter {
public:
    virtual ~ScalarConverter() = 0;
    static void convert(const std::string &s);
};
