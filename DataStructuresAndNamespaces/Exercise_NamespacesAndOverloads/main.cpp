/*
- Task 1:
Implements the following functions:
    - double mean_array_value(int *array, const std::size_t length);
    - double mean_array_value(double *array, const std::size_t length);
The first function is to calculate the mean of the int array. The second function is supposed to
calculate the mean of the double array.

This means we have a function overloading for different data types. The two functions
should be declared within the namespace "computation" in exercise.hpp and defined in exercise.cpp.

Example task 1
const std::uint32_t array_elements = 5;
int array_a[array_elements] = { 1, 2, 3, 4, 5 };
double array_b[array_elements] = { 1.0, 2.5, 3.5, 4.5, 10.0 };

double mean_array_a = computation::mean_array_value(array_a, array_elements);
double mean_array_b = computation::mean_array_value(array_b, array_elements);

// Output is: Mean Array A: 3
std::cout << "Mean Array A: " << mean_array_a << std::endl;
// Output is: Mean Array B: 4.3
std::cout << "Mean Array B: " << mean_array_b << std::endl;

- Task 2:
Creates a struct Dataset structure with the following attributes: mean_array_a and mean_array_b.

Example 2
struct Dataset
{
     TYPE ...;
     TYPE ...;
};
The structure should also be defined in the namespace "computation" in the file "exercise.h".
Then create a variable of this structure in the main function and save the mean values from task 1.
*/
#include <iostream>
#include <cstdint>

#include "exercise.hpp"

int main(void)
{
    const std::uint32_t array_elements = 5;
    int array_a[array_elements]{1, 2, 3, 4, 5};
    double array_b[array_elements]{1.0, 2.5, 3.5, 4.5, 10.0};

    double mean_array_a = computation::mean_array_value(array_a, array_elements);
    double mean_array_b = computation::mean_array_value(array_b, array_elements);

    std::cout << "Mean Array A: " << mean_array_a << '\n';
    std::cout << "Mean Array B: " << mean_array_b << '\n';

    computation::Dataset data{.mean_array_a = mean_array_a, .mean_array_b = mean_array_b};
    std::cout << data.mean_array_a << '\n';
    std::cout << data.mean_array_b << '\n';

    return 0;
}
