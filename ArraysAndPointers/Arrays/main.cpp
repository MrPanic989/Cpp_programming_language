#include <iostream>
#include <cstdint>

int main(void)
{
    constexpr auto length = std::uint32_t{5u};  //For arrays one should use constexpr.

    float vector1[length]{};    //Initialize the whole array with value 0.
    float vector2[length]{};

    std::cout << "Enter " << length << " values for vector1: ";
    for(std::uint32_t i = 0; i < length; ++i)
    {
        std::cin >> vector1[i];
    }

    std::cout << "Enter " << length << " values for vector2: ";
    for(std::uint32_t i = 0; i < length; ++i)
    {
        std::cin >> vector2[i];
    }

     for(std::uint32_t i = 0u; i < length; ++i)
    {
        std::cout << vector1[i] << " ";
    }
    std::cout << std::endl;

    for(std::uint32_t i = 0u; i < length; ++i)
    {
        std::cout << vector2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "The sum of the two values of each index from vector1 and vector2 is: ";
    for(std::uint32_t i = 0; i < length; ++i)
    {
        std::cout << vector1[i] + vector2[i] << " ";
    }
    std::cout << std::endl;

    float reversed_vector1[length]{};
    float reversed_vector2[length]{};

    std::cout << "The reversed vector1: ";
    for(std::uint32_t i = 0; i < length; ++i)
    {
        reversed_vector1[i] = vector1[length - 1 - i];
        std::cout << reversed_vector1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "The reversed vector2: ";
    for(std::uint32_t i = 0; i < length; ++i)
    {
        reversed_vector2[i] = vector2[length - 1 - i];
        std::cout << reversed_vector2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
