#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstdint>

typedef struct s_Data
{
    std::string name;
    std::string last_name;
    int id;
} Data;


class Serializer
{
    private:
    
    public:
        Serializer();
        Serializer(const Serializer& src);
        Serializer& operator=(const Serializer& src);
        ~Serializer();
        static std::uintptr_t serialize(Data* ptr);
        static Data* deserialize(std::uintptr_t raw);
};


#endif