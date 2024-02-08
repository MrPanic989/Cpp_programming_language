#include <cstddef>
#include <cstdint>
#include <vector>

#include "lib.hpp"

void remove_duplicates(std::vector<std::int32_t> &vector)
{
    for (std::size_t i = 0; i < vector.size(); i++)
    {
        auto duplicate_index = static_cast<std::size_t>(-1);
        const auto current_value = vector[i];

        for (std::size_t j = i + 1; j < vector.size(); j++)
        {
            if (current_value == vector[j])
            {
                duplicate_index = j;
                break;
            }
        }

        if (duplicate_index == static_cast<std::size_t>(-1))
        {
            continue;
        }

        for (std::size_t j = duplicate_index; j < vector.size(); j++)
        {
            vector[j] = vector[j + 1];
        }

        vector.pop_back();
    }
}

void rotate_left(std::vector<std::int32_t> &vector)
{
    const auto first_element = vector[0];

    for (std::size_t i = 1; i < vector.size(); i++)
    {
        vector[i - 1] = vector[i];
    }

    vector[vector.size() - 1] = first_element;
}

void rotate_right(std::vector<std::int32_t> &vector)
{
    const auto last_element = vector[vector.size() - 1];

    for (std::size_t i = vector.size() - 1; i > 0; i--)
    {
        vector[i] = vector[i - 1];
    }

    vector[0] = last_element;
}

void swap_boundary_values(std::vector<std::int32_t> &vector)
{
    //Don't forget the referece operator when using auto, because auto does not
    //do that automatically for you. If we would just use auto first = vector.front();, we would
    //just create a copy of the first element of the vector. Therefore, we also wouldt update
    //the actual value of the vector.
    auto &first = vector.front();
    auto &last = vector.back();
    const auto temp = first;

    first = last;
    last = temp;
}
