#include <iostream>
#include <vector>   //Has to be included for vector functions
#include <cstdint>

void print_vector(const std::vector<std::int32_t> &vec)
{
    for(std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ", ";
    }
    std::cout << std::endl;
}


//A vector is sort of a dynamical array, but with an advantage: we don't have to take caro of the
//memory allocation on the heap
int main(void)
{
    //Version 1 of initialization: 5 int32_t elements with value 0
    auto my_vector = std::vector<std::int32_t>(5, 0);
    print_vector(my_vector);

    my_vector[0] = 1223;
    print_vector(my_vector);

    //One of the strength of a vector is that it becomes easy to add or delete elements at the end
    my_vector.push_back(42);
    print_vector(my_vector);

    my_vector.pop_back();
    my_vector.pop_back();
    my_vector.pop_back();
    print_vector(my_vector);

    auto my_vector2 = std::vector<std::int32_t>{};

    for(std::size_t i = 0; i < 9; ++i)
    {
        my_vector2.push_back(i);
    }
    std::cout << "Size: " << my_vector2.size() << '\n';
    std::cout << "Capacity: " << my_vector2.capacity() << '\n';

    return 0;
}
