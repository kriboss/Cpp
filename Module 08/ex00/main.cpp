#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

const char *NotFoundException::what() const throw()
{
    return "Element not found in container";
}

int main(void)
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(9);

    std::list<int> lst;
    lst.push_back(2);
    lst.push_back(8);
    lst.push_back(4);
    lst.push_back(6);

    // Test vector
    std::cout << "Testing with vector:" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found 5 in vector at value: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        easyfind(vec, 10);
        std::cout << "Found 10 in vector" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test list
    std::cout << "\nTesting with list:" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, 8);
        std::cout << "Found 8 in list at value: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        easyfind(lst, 1);
        std::cout << "Found 1 in list" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
