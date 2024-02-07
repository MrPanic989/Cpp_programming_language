/*Implement the following functions for the DynamicArray struct

struct DynamicArray
{
     double *m_data;
     std::size_t m_length;
};

double sum(const DynamicArray &dynamic_array)

double mean(const DynamicArray &dynamic_array)

double median(const DynamicArray &dynamic_array)

Please note that the mean and the median are different things.
You can also reuse one of the functions in another.

Note: you can expand our code from ../../ArraysAndPointers/Exercise_CreateOwnVector
*/
#include <cstdlib>
#include <iostream>

#include "AlgoArray.hpp"
#include "DynArray.hpp"

int main()
{
    auto fill_value = 1.0;
    auto length = std::size_t{11};

    auto my_array = create_dynamic_array(fill_value, length);   //Struct

    for (std::size_t i = 0; i < length; ++i)
    {
        my_array.m_data[i] = static_cast<double>(i);
    }

    std::cout << "Mean = " << mean(my_array) << '\n';
    std::cout << "Median = " << median(my_array) << '\n';

    return 0;
}
