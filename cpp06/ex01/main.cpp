#include <iostream>
#include "Serializer.hpp"

int main() 
{
    Data* test = new Data;
    test->name = "fahd";
    test->id = 1337;
    test->last_name = "benallal";

    std::cout << "Original Data address: " << &test << std::endl;

    uintptr_t raw = Serializer::serialize(test);
    std::cout << "Serialized (uintptr_t): " << raw << " (Hex: 0x" << std::hex << raw << std::dec << ")" << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << ptr << std::endl;

    if (ptr == test) 
    {
        std::cout << "SUCCESS: Addresses match!" << std::endl;
        std::cout << "Name: " << ptr->name << ", ID: " << ptr->id << ", last_name: " << ptr->last_name << std::endl;
    }
    else 
    {
        std::cout << "ERROR: Address mismatch!" << std::endl;
    }

    return 0;
}