#include <iostream>
#include <cstdint>

int main(void)
{
    //1d-Array (Vector)
    //int32_t my_array1[3] = {1, 2, 3};

    //2d-Array (Matrix)
    //Number of rows = 3
    //Number of columns = 2
    //int32_t my_matrix1[3][2] = {1, 2, 3, 4, 5, 6};

    constexpr static auto num_rows = std::uint32_t{3};  //uniform initialization
    constexpr static auto num_cols = std::uint32_t{2};  //uniform initialization

    std::int32_t my_matrix[num_rows][num_cols] = {{1, 2}, {3, 4}, {5, 6}};

    for(uint32_t i = 0; i < num_rows; ++i)
    {
        std::cout << my_matrix[i] << '\n';     //The result are three memory addresses of the first value
    }                                           //from each row (pointer values)!

    for(uint32_t i = 0; i < num_rows; ++i)
    {
        for(uint32_t j = 0; j < num_cols; ++j)
        {
            std::cout << my_matrix[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::int32_t column_sums[num_cols]{}; //Fills the array initially with 0

    for(std::uint32_t i = 0u; i < num_rows; ++i)
    {
        for(std::uint32_t j = 0u; j < num_cols; ++j)
        {
            column_sums[j] += my_matrix[i][j];
        }
    }

    for(std::uint32_t j = 0u; j < num_cols; ++j)
    {
        std::cout << "Sum at column " << j << " = " << column_sums[j] << '\n';
    }

    return 0;
}
