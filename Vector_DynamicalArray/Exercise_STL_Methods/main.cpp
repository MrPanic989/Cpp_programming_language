/*
- Task 1:
Initialize a 3x3 matrix in the main function, with the value (i + j) at index matrix[i][j].
Use the predefined matrix type from the header.

- Task 2:
Writes a function
    VectorT max_row_values(MatrixT &matrix);
which receives a matrix and calculates the row maxima of each row of the matrix and saves these maxima
in a new vector. The function then returns this newly created vector.

- Task 3:
Writes a function
    ValueT sort_and_max(VectorT &vec);
which receives a double vector and sorts it in ascending order and also returns
the maximum of the vector.
*/
#include <algorithm>
#include <iostream>
#include <vector>

#include "lib.hpp"

void printMatrix(const MatrixT &matrix)
{
    for (std::size_t i = 0; i != matrix.size(); ++i)
    {
        for (std::size_t j = 0; j != matrix[i].size(); ++j)
        {
            std::cout << "m[" << i << ", " << j << "] = " << matrix[i][j]
                      << '\n';
        }
    }
    std::cout << '\n';
}

void printVector(const VectorT &vec)
{
    for (std::size_t i = 0; i != vec.size(); ++i)
    {
        std::cout << "v[" << i << "] = " << vec[i] << '\n';
    }
    std::cout << '\n';
}

int main()
{
    // Exercise 1
    auto matrix = MatrixT(3, VectorT(3, 0.0));

    for (std::size_t i = 0; i != matrix.size(); ++i)
    {
        for (std::size_t j = 0; j != matrix[i].size(); ++j)
        {
            matrix[i][j] = static_cast<double>(i + j);
        }
    }

    std::cout << "Exercise 1:\n";
    printMatrix(matrix);

    // Exercise 2
    auto row_max_vec = max_row_values(matrix);
    std::cout << "max_row_values:\n";
    printVector(row_max_vec);

    // Exercise 3
    auto temp = row_max_vec[2];
    row_max_vec[2] = row_max_vec[1];
    row_max_vec[1] = temp;
    std::cout << "other order:\n";
    printVector(row_max_vec);

    const auto max = sort_and_max(row_max_vec);
    std::cout << "sort_and_max:\n";
    printVector(row_max_vec);

    std::cout << "Vector max: " << max << '\n';

    return 0;
}
