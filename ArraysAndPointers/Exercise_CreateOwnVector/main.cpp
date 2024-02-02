/*In this programming exercise we want to think about how we can implement “dynamic arrays”.
These describe heap arrays that can be resized.
By either reserving new memory on the heap or freeing memory again. (Keyword: new and delete)
These dynamic arrays are later called "Vector" in the standard library.

- Task 1
    -Write a function
        - void push_back(int* &input_array, const std::size_t size, const int value);
    which adds an element to the end of the dynamic array. Note that this increases the
    length of the array by one.

- Task 2
    -Write a function
        - void pop_back(int* &input_array, const std::size_t size);
    which removes the last element of the dynamic array. Note that this reduces
    the length of the array by one.
*/
#include <iostream>
#include <cstdint>

#include "lib.hpp"

int main(void)
{
    auto size = std::size_t{3};
    auto* my_data = new int[size];

    if(my_data == nullptr)
    {
        std::cout << "Memory allocation has failed!" << '\n';
        return 1;
    }

    for(std::size_t i = 0; i < size; ++i)
    {
        my_data[i] = static_cast<int>(i);
    }

    std::cout << "The array looks like this: ";
    for(std::size_t i = 0; i < size; ++i)
    {
        std::cout << my_data[i] << " ";
    }
    std::cout << std::endl;

    auto add = int{0};
    std::cout << "What number do you want to add at the end of the array: ";
    std::cin >> add;

    push_back(my_data, size, add);
    ++size;

    std::cout << "The array looks like this: ";
    for(std::size_t i = 0; i < size; ++i)
    {
        std::cout << my_data[i] << " ";
    }
    std::cout << std::endl;

    pop_back(my_data, size);
    --size;

    std::cout << "The array looks like this: ";
    for(std::size_t i = 0; i < size; ++i)
    {
        std::cout << my_data[i] << " ";
    }
    std::cout << std::endl;

    delete[] my_data;
    my_data = nullptr;

    return 0;
}
