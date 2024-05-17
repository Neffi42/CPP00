#include "Serializer.hpp"
#include <cstddef>
#include <cstdint>
#include <iostream>

int main() {
    {
        Data data = {"Bob", "Ruler of the Galaxy", 42};
        uintptr_t uiptr = Serializer::serialize(&data);
        Data* ptr = Serializer::deserialize(uiptr);
        std::cout << "Original address: " << &data << "\n";
        std::cout << "Serialized address: " << uiptr << "\n";
        std::cout << "Deserialized address: " << ptr << "\n";
    }
    {
        Data* data = NULL;
        uintptr_t uiptr = Serializer::serialize(data);
        Data* ptr = Serializer::deserialize(uiptr);
        std::cout << "Original address: " << data << "\n";
        std::cout << "Serialized address: " << uiptr << "\n";
        std::cout << "Deserialized address: " << ptr << "\n";
    }
}
