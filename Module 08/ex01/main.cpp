#include <iostream>
#include <vector>
#include "Span.hpp"

int main(void)
{
    std::cout << "=== Basic Test ===" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    std::cout << "\n=== Full Span Test ===" << std::endl;
    try
    {
        sp.addNumber(1);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Empty Span Test ===" << std::endl;
    Span empty(10);
    try
    {
        empty.shortestSpan();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Single Element Test ===" << std::endl;
    Span single(10);
    single.addNumber(42);
    try
    {
        single.longestSpan();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Range Add Test ===" << std::endl;
    Span sp2(10000);
    std::vector<int> range;
    for (int i = 0; i < 10000; ++i)
        range.push_back(i);

    sp2.addNumbers(range.begin(), range.end());
    std::cout << "Shortest span (0-9999): " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span (0-9999): " << sp2.longestSpan() << std::endl;

    std::cout << "\n=== Large Span Test ===" << std::endl;
    Span large(1000);
    std::vector<int> values;
    for (int i = 0; i < 1000; ++i)
        values.push_back(i * 2);

    large.addNumbers(values.begin(), values.end());
    std::cout << "Shortest span (0,2,4,...1998): " << large.shortestSpan() << std::endl;
    std::cout << "Longest span (0,2,4,...1998): " << large.longestSpan() << std::endl;

    return 0;
}
