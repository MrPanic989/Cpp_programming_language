#include <iostream>
#include <cstdint>

#include "lib.hpp"

void push_back(int* &input_array, const std::size_t size, const int value)
{
    auto new_size = std::size_t{size + 1};
    auto* new_array = new int[new_size];

    if(new_array == nullptr)
    {
        std::cout << "Memory allocation has failed!" << '\n';
        std::exit(1);   //Exit with failure in a void function
    }

    for(std::size_t i = 0; i < size; ++i)
    {
        new_array[i] = input_array[i];
    }
    new_array[size] = value;

    delete[] input_array;
    input_array = new_array;
}

void pop_back(int* &input_array, const std::size_t size)
{
    auto new_size = std::size_t{size - 1};
    auto* new_array = new int[new_size];

    if(new_array == nullptr)
    {
        std::cout << "Memory allocation has failed!" << '\n';
        std::exit(1);   //Exit with failure in a void function
    }

    for(std::size_t i = 0; i < new_size; ++i)
    {
        new_array[i] = input_array[i];
    }

    delete[] input_array;
    input_array = new_array;
}
