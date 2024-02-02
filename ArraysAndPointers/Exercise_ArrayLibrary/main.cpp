/*Implement the following functions:
- void remove_duplicates(std::int32_t *array, std::size_t &length);
    -Remove all duplicates in the array
    -By Remove I mean move the element to the end of the array and decrease the length
     of the array by one, hence the value is not used anymore

- void rotate_left(std::int32_t *array, std::size_t length);
    -Rotate all elements of the array to the left
     Rotate Left: [1, 2, 3] => [2, 3, 1]

- void rotate_right(std::int32_t *array, std::size_t length);
    -Rotate all elements of the array to the right
     Rotate Right: [1, 2, 3] => [3, 1, 2]

Note: Make sure that the input pointers are valid!
Note: Assume that a number can be at most 2 times in the array!
Note: main.cpp, asserts and utils.hpp are given!
*/
#include <cassert>
#include <cstring>
#include <iostream>

#include "lib.hpp"
#include "utils.hpp"

void test_cases();

int main()
{
    std::size_t length = 6;
    std::int32_t array[]{1, 1, 2, 3, 3, 4};

    remove_duplicates(array, length);
    print_array(array, length);

    rotate_left(array, length);
    print_array(array, length);

    rotate_right(array, length);
    print_array(array, length);

    test_cases(); // This should not fail

    return 0;
}

void test_cases()
{
    std::size_t length = 6;
    std::int32_t array[]{1, 1, 2, 3, 3, 4};
    std::int32_t array_cpy[]{1, 1, 2, 3, 3, 4};
    std::int32_t array_del[]{1, 2, 3, 4};

    rotate_left(array_cpy, length);
    assert(ranges_are_same(array, array_cpy, length) == false);
    rotate_right(array_cpy, length);
    assert(ranges_are_same(array, array_cpy, length) == true);

    remove_duplicates(array_cpy, length);
    assert(ranges_are_same(array_cpy, array_del, length) == true);
    assert(ranges_are_same(array, array_del, length) == false);
}
