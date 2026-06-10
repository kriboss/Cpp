#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <sstream>

static bool parseArgs(int argc, char **argv, std::vector<int> &out)
{
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream ss(argv[i]);
        int v;
        if (!(ss >> v)) return false;
        if (v < 0) return false;
        out.push_back(v);
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::vector<int> input;
    if (!parseArgs(argc, argv, input))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < input.size(); ++i)
    {
        if (i) std::cout << ' ';
        std::cout << input[i];
    }
    std::cout << std::endl;

    std::vector<int> v = input;
    std::deque<int> d(input.begin(), input.end());

    clock_t start = clock();
    sortVector(v);
    clock_t end = clock();
    double tvec = (double)(end - start) / CLOCKS_PER_SEC * 1000000.0; // microseconds

    clock_t start2 = clock();
    sortDeque(d);
    clock_t end2 = clock();
    double tdeq = (double)(end2 - start2) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (i) std::cout << ' ';
        std::cout << v[i];
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << tvec << " us" << std::endl;
    std::cout << "Time to process a range of " << v.size() << " elements with std::deque : " << tdeq << " us" << std::endl;
    return 0;
}
