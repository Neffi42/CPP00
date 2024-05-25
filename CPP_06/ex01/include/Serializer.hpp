#pragma once

#include <string>
#include <stdint.h>

typedef struct {
    std::string name;
    std::string job;
    unsigned int age;
} Data;

class Serializer {
public:
    virtual ~Serializer() = 0;
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
