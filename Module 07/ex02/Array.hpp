#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
  private:
    T *_data;
    unsigned int _size;

  public:
    Array(void);
    Array(unsigned int n);
    Array(const Array &other);
    ~Array(void);

    Array &operator=(const Array &other);

    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;

    unsigned int size(void) const;

    class OutOfBoundsException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#include "Array.tpp"

#endif
