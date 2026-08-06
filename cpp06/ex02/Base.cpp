#include "Base.hpp"
#include <stdlib.h>


Base::~Base() {}

Base * generate(void)
{
    int rand = std::rand() % 3;
    if(rand == 0)
        return new A();
    else if(rand == 1)
        return new B();
    else 
        return new C();
}
void identify(Base* p)
{

    if(A *son = dynamic_cast<A *>(p))
    {
        (void) son;
        std::cout << "[A]\n";
    }
    else if(B *son = dynamic_cast<B *>(p))
    {
        (void) son;

        std::cout << "[B]\n";
    }
    else if(C *son = dynamic_cast<C *>(p))
    {
        (void) son;

        std::cout << "[C]\n";
    }
    else 
    {
        (void) son;

        std::cout << "Cast fails,  Canot identify \n";
    }
}
void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return ;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {        
        C &c = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        (void)c;
        return ;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
       
}