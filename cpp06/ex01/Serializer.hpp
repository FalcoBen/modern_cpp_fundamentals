#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

class Serializer
{
    private:
    
    public:
        Serializer();
        Serializer(const Serializer& src);
        Serializer& operator=(const Serializer& src);
        ~Serializer();
        // static uintptr_t serialize(Data* ptr);
        // Data* deserialize(uintptr_t raw);
};


#endif