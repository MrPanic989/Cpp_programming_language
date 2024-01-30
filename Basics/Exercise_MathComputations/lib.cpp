#include <iostream>
#include <cstdint>
#include <cmath>

#include "lib.h"

double calculate_pi(const std::uint32_t num_iterations)
{
    double sum = 0.0;

    for(uint32_t i = 0u; i < num_iterations; ++i)
    {
        sum += (1.0 / (4.0 * i + 1.0) - 1.0 / (4.0 * i + 3.0));
    }

    return sum * 4.0;
}

void print_dec_to_bin(std::uint8_t value)
{
    std::cout << "The binary representation of value is: ";
    for(int8_t i = 7; i >= 0; --i)
    {
        std::uint8_t current_exponent = static_cast<std::uint8_t>(std::pow(2, i));

        if(current_exponent <= value)
        {
            std::cout << "1 ";
            value -= current_exponent;
        }
        else
        {
            std::cout << "0 ";
        }
    }
    std::cout << "\n";
}
