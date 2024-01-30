/*In this exercise, you have to use the datatype char to convert/check certain char values.

Implement the following checks:
- bool is_numeric(const char character);
- bool is_alpha(const char character);
- bool is_alpha_numeric(const char character);
- bool is_upper_case(const char character);
- bool is_lower_case(const char character);

These functions should return true or false.

Meaning of the function names:

Numeric: 0-9 (digits)
Alpha: a-z, A-Z (alphabeth characters)
Upper Case: A-Z
Lower Case: a-z
Note:

The shift from Upper Case to Lower Case is 32 in the ASCII table.

E.g. 'A' -> 'a' by adding 32 E.g. 'a' -> 'A' by subtracting 32

You do not have to look up the ASCII table for this exercise, but you can do so.

Afterward, implement the following conversion functions:
- char to_upper_case(const char character);
- char to_lower_case(const char character);

These should return the converted character.
The main() and the asserts are given.
*/
#include <cassert>
#include <iostream>

#include "lib.h"

void test_cases();

int main()
{
    char input_character;

    std::cout << "Please enter any ASCII character: ";
    std::cin >> input_character;

    std::cout << std::boolalpha;
    std::cout << "numeric: " << is_numeric(input_character) << '\n';
    std::cout << "alpha: " << is_alpha(input_character) << '\n';
    std::cout << "alpha_numeric: " << is_alpha_numeric(input_character) << '\n';
    std::cout << "upper_case: " << is_upper_case(input_character) << '\n';
    std::cout << "lower_case: " << is_lower_case(input_character) << '\n';
    std::cout << std::dec;
    std::cout << "to_upper_case: " << to_upper_case(input_character) << '\n';
    std::cout << "to_lower_case: " << to_lower_case(input_character) << '\n';

    test_cases(); // These tests should not fail!

    return 0;
}

void test_cases()
{
    const auto lowercase_alpha = 'a';
    const auto uppercase_alpha = 'A';
    const auto numeric = '5';
    const auto something_else = '#';

    assert(is_numeric(lowercase_alpha) == false);
    assert(is_numeric(uppercase_alpha) == false);
    assert(is_numeric(numeric) == true);
    assert(is_numeric(something_else) == false);

    assert(is_alpha(lowercase_alpha) == true);
    assert(is_alpha(uppercase_alpha) == true);
    assert(is_alpha(numeric) == false);
    assert(is_alpha(something_else) == false);

    assert(is_alpha_numeric(lowercase_alpha) == true);
    assert(is_alpha_numeric(uppercase_alpha) == true);
    assert(is_alpha_numeric(numeric) == true);
    assert(is_alpha_numeric(something_else) == false);

    assert(is_upper_case(lowercase_alpha) == false);
    assert(is_upper_case(uppercase_alpha) == true);
    assert(is_upper_case(numeric) == false);
    assert(is_upper_case(something_else) == false);

    assert(is_lower_case(lowercase_alpha) == true);
    assert(is_lower_case(uppercase_alpha) == false);
    assert(is_lower_case(numeric) == false);
    assert(is_lower_case(something_else) == false);

    assert(to_upper_case(lowercase_alpha) == uppercase_alpha);
    assert(to_upper_case(uppercase_alpha) == uppercase_alpha);
    assert(to_upper_case(numeric) == numeric);
    assert(to_upper_case(something_else) == something_else);
}
