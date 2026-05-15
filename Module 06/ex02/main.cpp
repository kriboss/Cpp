#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    // Generate and identify several times
    for (int i = 0; i < 10; ++i) {
        Base* p = generate();
        std::cout << "identify(Base*): ";
        identify(p);
        std::cout << "identify(Base&): ";
        identify(*p);
        delete p;
    }
    return 0;
}
