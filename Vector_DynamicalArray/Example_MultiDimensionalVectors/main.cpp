#include <iostream>
#include <cstdint>
#include <vector>

int main(void)
{
    /*Version, if we want to initialize our vectors all with the same value
    const auto num_elements = std::int32_t{2};
    const auto values = std::int32_t{5};
    const auto rows = std::vector<std::int32_t>(num_elements, values);

    auto my_vector = std::vector<std::vector<std::int32_t>>(3, rows);
    */


    //Create a 3x2 vector of integer, that is 3 vectors with 2 values -> vector of vectors
    auto my_vector = std::vector<std::vector<std::int32_t>>{{1, 2}, {3, 4}, {5, 6}};

    for(const auto &row : my_vector)
    {
        for(const auto &value : row)
        {
            std::cout << value << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
