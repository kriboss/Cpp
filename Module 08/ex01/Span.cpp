#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span::~Span(void)
{
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw FullException();
    _numbers.push_back(number);
}

int Span::shortestSpan(void) const
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = INT_MAX;
    for (unsigned int i = 1; i < sorted.size(); ++i)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }

    return minSpan;
}

int Span::longestSpan(void) const
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return maxVal - minVal;
}

const char *Span::FullException::what() const throw()
{
    return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
    return "No span found (need at least 2 numbers)";
}
