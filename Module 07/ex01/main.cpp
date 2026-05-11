#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T &value)
{
    std::cout << value << std::endl;
}

void incrementInt(int &value)
{
    ++value;
}

int main(void)
{
    int numbers[5] = {1, 2, 3, 4, 5};
    const std::string words[3] = {"hello", "42", "templates"};

    ::iter(numbers, 5, incrementInt);
    std::cout << "Incremented ints:" << std::endl;
    ::iter(numbers, 5, printElement<int>);

    std::cout << "Const strings:" << std::endl;
    ::iter(words, 3, printElement<std::string>);

    return 0;
}
