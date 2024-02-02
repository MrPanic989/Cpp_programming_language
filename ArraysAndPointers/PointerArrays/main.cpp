#include <iostream>
#include <cstdint>

int main(void)
{
    auto array_size = std::size_t{10};
    //Heap allocation: allocates array_size * sizeof(std::int32_t) = 40Byte, and returns the
    //heap memory address of the first element from that array
    auto* array = new std::int32_t[array_size];

    if(array == nullptr)
    {
        return 1;
    }

    for(std::size_t i = 0; i < array_size; ++i)
    {
        array[i] = static_cast<std::int32_t>(i);
    }

    // ...

    for(std::size_t i = 0; i < array_size; ++i)
    {
        std::cout << array[i] << '\n';
    }

    delete[] array; //If you allocate with new[], than you should use delete[] also, otherwise
                    //you would free up just the first storage space of the array

    array = nullptr;    //It is a safe replacement for the null pointer (NULL) and avoids pointer problems

    return 0;
}
