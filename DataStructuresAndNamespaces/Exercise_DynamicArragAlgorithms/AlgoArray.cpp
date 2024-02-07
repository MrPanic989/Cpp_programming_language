#include <cmath>
#include <cstdlib>

#include "AlgoArray.hpp"
#include "DynArray.hpp"

double sum(const DynamicArray &dynamic_array)
{
    auto total = 0.0;

    for(std::size_t i = 0; i < dynamic_array.m_length; ++i)
    {
        total += dynamic_array.m_data[i];
    }

    return total;
}

double mean(const DynamicArray &dynamic_array)
{
    return sum(dynamic_array) / static_cast<double>(dynamic_array.m_length);
}

double median(const DynamicArray &dynamic_array)
{
    if(dynamic_array.m_length % 2 == 0)
    {
        const std::size_t first_index = dynamic_array.m_length / 2;
        const std::size_t second_index = first_index - 1;

        return (dynamic_array.m_data[first_index] + dynamic_array.m_data[second_index]) / 2.0;
    }

    const std::size_t index = dynamic_array.m_length / 2;

    return dynamic_array.m_data[index];
}
