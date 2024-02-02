#include <iostream>
#include <cstdint>

#include "lib.hpp"

bool all_of(const std::int32_t* array, const std::size_t length, const std::int32_t value)
{
    if(array == nullptr || length == 0)
    {
        return false;
    }

    for(std::size_t i = 0; i < length; ++i)
    {
        if(array[i] != value)
        {
            return false;
        }
    }

    return true;
}

bool any_of(const std::int32_t* array, const std::size_t length, const std::int32_t value)
{
    if(array == nullptr || length == 0)
    {
        return false;
    }

    for(std::size_t i = 0; i < length; ++i)
    {
        if(array[i] == value)
        {
            return true;
        }
    }

    return false;
}

bool none_of(const std::int32_t* array, const std::size_t length, const std::int32_t value)
{
    if(array == nullptr || length == 0)
    {
        return false;
    }

    for(std::size_t i = 0; i < length; ++i)
    {
        if(array[i] == value)
        {
            return false;
        }
    }

    return true;
}

std::size_t count(const std::int32_t* array, const std::size_t length, const std::int32_t value)
{
    if(array == nullptr || length == 0)
    {
        return 0;
    }
    std::size_t count = 0;

    for(std::size_t i = 0; i < length; ++i)
    {
        if(array[i] == value)
        {
            ++count;
        }
    }

    return count;
}
