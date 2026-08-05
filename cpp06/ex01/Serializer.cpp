#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& src)
{
}

Serializer& Serializer::operator=(const Serializer& src)
{
    (void)src;
    if(this != &src)
    {

    }
    return *this;
}

std::uintptr_t Serializer::serialize(Data* ptr)
{
    // std::cout << "----serializing-----" << std::endl;
    // std::cout << "name = " << ptr->name << std::endl;
    // std::cout << "last_name = " << ptr->last_name << std::endl;
    // std::cout << "id = " << ptr->id << std::endl;
    return reinterpret_cast<std::uintptr_t>(ptr);
}

Data* Serializer::deserialize(std::uintptr_t raw)
{
    // std::cout << "----diserializing-----" << std::endl;
    // std::cout << "inisde object raw = " << raw << std::endl;
    return reinterpret_cast<Data*>(raw);
}

Serializer::~Serializer()
{
}
