/*Implement the following functions:

void remove_duplicates(std::vector<std::int32_t> &vector);

void rotate_left(std::vector<std::int32_t> &vector);

void rotate_right(std::vector<std::int32_t> &vector);

void swap_boundaryValues(std::vector<std::int32_t> &vector);

Swap Boundary Values: Swap the first and the last value of the array
E.g. [1, 2, 3, 4] => [4, 2, 3, 1]

Note: Adapt the functions from Chapter ArraysAndPointers such that you use vectors as an input.
*/
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

#include "lib.hpp"
#include "utils.hpp"

void test_cases();

int main()
{
    auto vector = std::vector<std::int32_t>{1, 1, 2, 3, 3, 4};

    std::cout << "remove_duplicates: " << '\n';
    remove_duplicates(vector);
    print_vector(vector);

    std::cout << "rotate_left: " << '\n';
    rotate_left(vector);
    print_vector(vector);

    std::cout << "rotate_right: " << '\n';
    rotate_right(vector);
    print_vector(vector);

    std::cout << "swap boundary values: " << '\n';
    swap_boundary_values(vector);
    print_vector(vector);

    test_cases();

    return 0;
}

void test_cases()
{
    auto vec = std::vector<std::int32_t>{1, 1, 2, 3, 3, 4};
    auto vec_swap = std::vector<std::int32_t>{4, 1, 2, 3, 3, 1};
    auto vec_cpy = std::vector<std::int32_t>{1, 1, 2, 3, 3, 4};
    auto vec_del = std::vector<std::int32_t>{1, 2, 3, 4};

    rotate_left(vec_cpy);
    assert(vectors_are_same(vec, vec_cpy) == false);
    rotate_right(vec_cpy);
    assert(vectors_are_same(vec, vec_cpy) == true);

    remove_duplicates(vec_cpy);
    assert(vectors_are_same(vec_cpy, vec_del) == true);
    assert(vectors_are_same(vec, vec_del) == false);

    swap_boundary_values(vec);
    assert(vectors_are_same(vec, vec_swap) == true);
}
