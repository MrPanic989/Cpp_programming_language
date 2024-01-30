/*In this exercise, you have to use the datatypes double and int for certain computations.

Implement the following functions:
- double calculate_pi(std::uint32_t num_iterations);
- void print_dec_to_bin(std::uint8_t value);

Calculate Pi:
With the following formula, you can compute pi/4.
Implement the formula in the function with n = num_iterations.
Use a for-loop to sum up the values.
x = pi/4 = sigma 1/(4n+1) - 1/(4n+3).
At the end multiply by 4 before you return the value.
So the returned value will be an approximation of pi and not pi/4.

Decimal to Binary:
Implement a function that prints out the binary representation of the positive decimal input.
E.g. the decimal number 142 would be 10001110 in binary.
If you do not know how the binary system works, refer to the Wikipedia link.
Since this knowledge is not only important for this exercise but in general for a programmer.

Hint
To compute 2^i you can use:

#include <cmath>

std::pow(2, i)
The main() and asserts are given.
*/
#include <cassert>
#include <cfloat>
#include <cmath>
#include <iomanip>
#include <iostream>

#include "lib.h"

void test_cases();

int main()
{
    std::uint32_t num_iterations = 1'000'000;
    double pi = 3.14159265358979323846;
    double pi_calculated = calculate_pi(num_iterations);

    std::cout << std::setprecision(30);
    std::cout << "pi (calculated): " << pi_calculated << '\n';
    std::cout << "pi (correct): " << pi << '\n';

    std::uint8_t dec = 142u;
    print_dec_to_bin(dec);

    test_cases(); // This should not fail!
}

void test_cases()
{
    const auto diff =
        std::fabs(calculate_pi(1'000'000) - 3.14159265358979323846);
    assert(diff < 1e-04);
}
