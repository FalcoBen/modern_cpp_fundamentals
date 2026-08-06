#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "--- Test " << (i + 1) << " ---" << std::endl;
        Base* ptr = generate();
        std::cout << "Identify via Pointer:   ";
        identify(ptr);

        std::cout << "Identify via Reference: ";
        identify(*ptr);

        delete ptr;
    }

    return 0;
}