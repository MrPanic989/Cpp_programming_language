#include <iostream>
#include <cstdint>

int main(void)
{
    //How to initialize an char array?
    const char first_name[] = {'S', 'i', 'k', 'i', '\0'};   //Version1
    const char last_name[] = "Pannationis";     //Version2

    std::cout << "My name is " << first_name << " " << last_name << std::endl;  //Works with char arrays (strings)

    const std::uint32_t length_last_name = sizeof(last_name) / sizeof(last_name[0]);
    for(std::uint32_t i = 0u; i < length_last_name - 1u; ++i)
    {
        std::cout << "Char[" << i << "]: " << last_name[i] << std::endl;
    }
    std::cout << std::endl;

    std::uint32_t count = 0u;

    while(first_name[count] != '\0')
    {
        count++;
    }
    std::cout << "The first name has " << count << " characters!" << std::endl;

    const std::int32_t values[]{1, 2, 3};
    std::cout << values << std::endl;       //Prints the memory address of the first element (pointer)

    return 0;
}
