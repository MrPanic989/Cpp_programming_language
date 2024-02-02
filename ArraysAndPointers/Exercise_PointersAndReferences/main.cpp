/*Task 1:

- First create a double pointer array with 100 elements, the value of which stores the
  numbers from 0 to 99 (tip: use for loop).

- Then write a function
    - double array_sum(double *p_array, const std::size_t length);
  which takes a pointer array of type double (1st argument), takes the length
  of the array (2nd argument) and calculates and returns the sum of the array.

- Example 1
  This means that the array with 100 elements would have the following sum:
    auto *d = new double[100];
    // Array values init here.
    auto sum = array_sum(d, 100);
    std::cout << sum << std::endl; // Result is: 4950

Task 2:

- Writes a function
    - std::int32_t* array_constructor(const std::int32_t value, const std::size_t length);
  which creates and returns a pointer array of type int. Please note that the length of the
  array and which value should be stored at each index of the array are passed.

- Example 2
    // value: 5, length: 3
    auto* array = array_constructor(5, 3)
    // array = { 5, 5, 5}
  This means that if you say the array should have 3 elements and the value is 5,
  the result will be an array with 3 indices with the value 5 everywhere.
*/
#include <iostream>
#include <cstdint>

#include "lib.h"

int main(void)
{                    //size_t is the exact data type for every OS to represent the length of a medium
    auto array_length = std::size_t{100};

    auto* array = new double[array_length];

    if(array == nullptr)
    {
        std::cout << "The memory allocation has failed.";
        return 1;
    }

    for(std::size_t i = 0; i < array_length; ++i)
    {
        array[i] = static_cast<double>(i);
    }
    /*
    for(std::size_t i = 0; i < array_length; ++i)
    {
        std::cout << array[i] << '\n';
    }
    */

    double sum = array_sum(array, array_length);
    std::cout << "The total sum of this array is: " << sum << '\n';

    std::cout << std::endl;

    auto creators_array_length = std::size_t{0};
    auto creators_array_value = std::int32_t{0};

    std::cout << "Now it is time to create your own array. Firstly choose the length of your array: ";
    std::cin >> creators_array_length;
    std::cout << "Which value should be stored at each index of the array: ";
    std::cin >> creators_array_value;

    auto* creators_array = array_constructor(creators_array_value, creators_array_length);
    std::cout << "Your array looks like this: ";
    for(std::size_t i = 0; i < creators_array_length; ++i)
    {
        std::cout << creators_array[i] << " ";
    }
    std::cout << std::endl;

    delete[] array; //If you allocate with new[], than you should use delete[] also, otherwise
                    //you would free up just the first storage space of the array
    delete[]creators_array;

    array = nullptr;    //It is a safe replacement for the null pointer (NULL) and avoids pointer problems
    creators_array = nullptr;

    return 0;
}
