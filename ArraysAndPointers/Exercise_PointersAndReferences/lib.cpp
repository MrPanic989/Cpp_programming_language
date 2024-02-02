#include <iostream>
#include <cstdint>

#include "lib.h"

double array_sum(double* p_array, const std::size_t length)
{
    if(p_array == nullptr)
    {
        return 1;
    }

    double total = 0.0;

    for(std::size_t i = 0; i < length; ++i)
    {
        total += p_array[i];
    }

    return total;
}

std::int32_t* array_constructor(const std::int32_t value, const std::size_t length)
{
    auto* array = new std::int32_t[length];

    if(array == nullptr)
    {
        std::cout << "Memory allocation has failed!" << '\n';
        return nullptr;
    }

    for(std::size_t i = 0; i < length; ++i)
    {
        array[i] = value;
    }

    return array;
}
