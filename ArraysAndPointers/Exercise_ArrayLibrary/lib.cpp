#include <iostream>
#include <cstdint>

#include "lib.hpp"

void remove_duplicates(std::int32_t* array, std::size_t &length)
{
    if(array == nullptr || length == 0)
    {
        return;
    }

    for(std::size_t i = 0; i < length - 1; ++i)
    {
        for(std::size_t j = i + 1; j < length; ++j)
        {
            if(array[i] == array[j])
            {
                for(std::size_t k = j; k < length - 1; ++k)
                {
                    std::int32_t temp = array[k];
                    array[k] = array[k + 1];
                    array[k + 1] = temp;
                }
                --length;
                --j;
            }

        }

    }
}

void rotate_left(std::int32_t* array, const std::size_t length)
{
    if(array == nullptr || length == 0)
    {
        return;
    }

    for(std::size_t i = 0; i < length - 1; ++i)
    {
        std::int32_t temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }
}

void rotate_right(std::int32_t* array, const std::size_t length)
{
    if(array == nullptr || length == 0)
    {
        return;
    }

    for(std::size_t i = 0; i < length - 1; ++i)
    {
        static std::int32_t pull = 0;
        static std::int32_t to_swap = 0;

        if(i == 0)
        {
            std::int32_t last = array[length - 1];
            pull = array[i + 1];
            array[i + 1] = array[i];
            array[i] = last;
        }
        else
        {
            to_swap = array[i + 1];
            array[i + 1] = pull;
            pull = to_swap;
        }

    }
}
