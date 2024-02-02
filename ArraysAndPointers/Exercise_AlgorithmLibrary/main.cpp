/*Implement the following functions:
- bool all_of(const std::int32_t* array, const std::size_t length, const std::int32_t value);
    -Returns true if all elements in the array are equal to the value
    E.g. all_of([1, 1, 1], 3, 1) => true
    E.g. all_of([1, 1, 2], 3, 1) => false

- bool any_of(const std::int32_t* array, const std::size_t length, const std::int32_t value);
    -Returns true if at least one element in the array is equal to the value
    E.g. any_of([1, 1, 1], 3, 1) => true
    E.g. any_of([1, 1, 2], 3, 1) => true

- bool none_of(const std::int32_t* array, const std::size_t length, const std::int32_t value);
    -Returns true if all elements in the array are not equal to the value
    E.g. none_of([1, 1, 1], 3, 1) => false
    E.g. none_of([1, 1, 2], 3, 1) => false

- std::size_t count(const std::int32_t* array, const std::size_t length, const std::int32_t value);
    -Counts the elements in the array that are equal to the value
    E.g. count([1, 1, 1], 3, 1) => 3
    E.g. count([1, 1, 2], 3, 1) => 2
Note: Make sure that the input pointers are valid (not nullptr and length > 0).
main.cpp, asserts and utils.hpp are given.
*/
#include <cassert>
#include <cstdint>
#include <iostream>

#include "lib.hpp"
#include "utils.hpp"

void test_cases();

int main()
{
    const std::int32_t array[]{3, 1, 4, 1, 5, 9, 2, 6};
    const std::size_t length = 8;

    std::cout << std::boolalpha;
    std::cout << "all_of: " << all_of(array, length, 5) << '\n';
    std::cout << "any_of: " << any_of(array, length, 5) << '\n';
    std::cout << "none_of: " << none_of(array, length, 5) << '\n';
    std::cout << "count: " << count(array, length, 1) << '\n';

    test_cases(); // This should not fail!

    return 0;
}

void test_cases()
{
    const std::int32_t array[]{2, 1, -2, 0, -1};
    const std::size_t length = 5;

    assert(all_of(nullptr, length, 2) == false);
    assert(any_of(nullptr, length, 2) == false);
    assert(none_of(nullptr, length, 2) == false);

    assert(count(array, length, 1) == 1);
    assert(count(array, length, -3) == 0);

    assert(any_of(array, length, 2) == true);
    assert(any_of(array, length, 1) == true);
    assert(any_of(array, length, 0) == true);
    assert(any_of(array, length, -1) == true);
    assert(any_of(array, length, -2) == true);

    assert(none_of(array, length, 3) == true);
    assert(none_of(array, length, 2) == false);
    assert(none_of(array, length, 1) == false);
    assert(none_of(array, length, 0) == false);
    assert(none_of(array, length, -1) == false);
    assert(none_of(array, length, -2) == false);
    assert(none_of(array, length, -3) == true);
}
