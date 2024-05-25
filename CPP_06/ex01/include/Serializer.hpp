#pragma once

#include <cstdint>
#include <string>

typedef struct {
    std::string name;
    std::string job;
    unsigned int age;
} Data;

class Serializer {
private:
    Serializer();
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
