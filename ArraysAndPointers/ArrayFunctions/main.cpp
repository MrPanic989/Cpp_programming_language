#include <iostream>
#include <cstdint>
#include <array> // Only in C++

/*This was the C style approach!
                    //size_t is the exact data type for every OS to represent the length of a medium
void print_array(const std::int32_t arr[], const std::size_t len)
{
    for(std::size_t i = 0; i < len; ++i)
    {
        std::cout << arr[i] << '\n';
    }
}


int main(void)
{
    const std::int32_t values[]{1, 2, 3, 4};
    std::size_t length = sizeof(values) / sizeof(values[0]);

    print_array(values, length);    //If you call up a function with an array, you also have to give
                                    //the length to a function as parameter
}
*/

//C++ style approach:
// std::array<dataType, length>variableName = {values};

template <std::size_t N>    //To make the function general, for every size, we can create a template
void print_array(std::array<std::int32_t, N> arr)
{
    for(std::size_t i = 0u; i < arr.size(); ++i)
    {
        std::cout << arr[i] << '\n';
        arr[i] += 5;        //Nothing will change because we pass just a copy of the array to the function
    }
}


int main(void)
{                   //size_t is the exact data type for every OS to represent the length of a medium
    constexpr static std::size_t array_length1 = 4u;
    std::array<std::int32_t, array_length1> array1{1, 2, 3, 4};
    print_array(array1);

    std::cout << "Second try: " << '\n';
    print_array(array1);

    constexpr static std::size_t array_length2 = 6u;
    std::array<std::int32_t, array_length2> array2{4, 56, -1, 4, 233, -1324};
    print_array(array2);

    /*
    std::array is a constant array, that means that the length has to be known at compiletime.
    There is certainly a better alternative which we will get to know in the future, and that is
    std::vector <- dynamical array
    std::string <- dynamical char array
    */


    return 0;
}
