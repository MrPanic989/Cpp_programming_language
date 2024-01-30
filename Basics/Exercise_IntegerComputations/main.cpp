/*In this exercise, you have to use an int datatype for certain computations.

Implement the following functions:
- std::uint32_t modulo(std::uint32_t number_a, std::uint32_t number_b);
    -Implement the modulo operator (a % b = c)
    E.g. 10 % 4 = 2, 10 % 3 = 1, 10 % 2 = 0

- std::uint32_t sum_of_digits(std::uint32_t number);
    -Number of decimal digits
    E.g. 128 = 3 Digits

- std::uint32_t cross_sum(std::uint32_t number);
    -Add up all decimal digits
    E.g. 123 = 6, 1234 = 10

Note:
The datatype std::uint32_t is defined in the cstdint header file.
These datatypes ensure that for every operating system and compiler
the value range is the same (for exactly this type 32 bit).

The main() and assert tests are given.
*/
#include <cassert>

#include <cstdint>
#include <iostream>

#include "lib.h"

void test_cases();

int main()
{
    std::uint32_t input_number = 0;

    std::cout << "Please enter a unsinged integer: ";
    std::cin >> input_number;

    std::cout << input_number << " % 3: " << modulo(input_number, 3) << '\n';
    std::cout << "sum_of_digits: " << sum_of_digits(input_number) << '\n';
    std::cout << "cross_sum: " << cross_sum(input_number) << '\n';

    test_cases();
}

void test_cases()
{
    assert(modulo(0, 3) == 0);
    assert(modulo(1, 3) == 1);
    assert(modulo(2, 3) == 2);
    assert(modulo(3, 3) == 0);

    assert(modulo(0, 0) == 0);
    assert(modulo(1, 0) == 0);

    assert(sum_of_digits(0) == 1);
    assert(sum_of_digits(10) == 2);
    assert(sum_of_digits(100) == 3);
    assert(sum_of_digits(1000) == 4);

    assert(cross_sum(0) == 0);
    assert(cross_sum(10) == 1);
    assert(cross_sum(100) == 1);
    assert(cross_sum(1000) == 1);
    assert(cross_sum(1234) == 10);
    assert(cross_sum(1235) == 11);
}
