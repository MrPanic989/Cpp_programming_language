#include <iostream> //Including standard stream objects
#include <cstdint>  //For predefined data types

int main(void)
{
    //cout = console output             //endl = end line (instead of '\n');
    std::cout << "Hello World!" << std::endl;

    uint32_t my_integer_value1 = 0;   //unsigned(positive) integer number | unique variable name | value
    std::uint32_t my_integer_value2 = 0;    //equivalent to the expression above

    std::cout << "Please enter the two integer numbers: ";
    std::cin >> my_integer_value1;
    std::cin >> my_integer_value2;

    float my_float_value1 = 0.0f; //floating point number | unique variable name | value
    float my_float_value2 = 0.0f;

    std::cout << "Please enter the first floating point number: ";
    std::cin >> my_float_value1;
    std::cout << "Please enter the second floating point number: ";
    std::cin >> my_float_value2;


    uint32_t my_integer_result;
    float my_float_result;

    my_integer_result = my_integer_value1 + my_integer_value2;
    my_float_result = my_float_value1 + my_float_value2;

    std::cout << "Addition integer: " << my_integer_result << std::endl;    //C++ way of command
    printf("Addition floating point number: %f\n", my_float_result);    //C was of command, also working in C++

    char letter_a1 = 'A';

    std::cout << "The letter_a1 is a " << letter_a1 << " letter." << std::endl;
    std::cout << "It has the decimal value " << (int)letter_a1 << " in the ASCII table." << std::endl << std::endl;

    char letter_a2 = letter_a1 + 3;

    std::cout << "The letter_a2 is a " << letter_a2 << " letter." << std::endl;
    std::cout << "It has the decimal value " << (int)letter_a2 << " in the ASCII table." << std::endl;

    return 0;
}
