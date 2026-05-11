#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void iter(T *array, const unsigned int length, F function)
{
    if (array == 0)
        return;
    for (unsigned int i = 0; i < length; ++i)
        function(array[i]);
}

template <typename T, typename F>
void iter(const T *array, const unsigned int length, F function)
{
    if (array == 0)
        return;
    for (unsigned int i = 0; i < length; ++i)
        function(array[i]);
}

#endif
