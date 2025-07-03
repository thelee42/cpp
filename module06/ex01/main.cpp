#include    "Serializer.hpp"
#include    <iostream>

int main() {
    Data original;
    original.id = 42;
    original.name = "Hello";

    uintptr_t raw = Serializer::serialize(&original);

    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Original pointer:  " << &original << std::endl;
    std::cout << "Recovered pointer: " << recovered << std::endl;

    std::cout << "Original data: id = " << original.id
              << ", name = " << original.name << std::endl;
    std::cout << "Recovered data: id = " << recovered->id
              << ", name = " << recovered->name << std::endl;

    return 0;
}