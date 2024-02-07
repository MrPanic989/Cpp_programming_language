#pragma once

#include <cstdint>

namespace computation
{
    double mean_array_value(int* array, const std::size_t length);
    double mean_array_value(double* array, const std::size_t length);

    struct Dataset
    {
        double mean_array_a;
        double mean_array_b;
    };
}
