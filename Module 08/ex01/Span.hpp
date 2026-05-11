#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
  private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

  public:
    Span(unsigned int n);
    Span(const Span &other);
    ~Span(void);

    Span &operator=(const Span &other);

    void addNumber(int number);

    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end)
    {
        for (InputIterator it = begin; it != end; ++it)
            addNumber(*it);
    }

    int shortestSpan(void) const;
    int longestSpan(void) const;

    class FullException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class NoSpanException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#endif
