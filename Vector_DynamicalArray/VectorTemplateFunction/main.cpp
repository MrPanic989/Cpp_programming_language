#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

template <typename ValueType>
void fill_vector(std::vector<ValueType> &vec)
{
    for(std::size_t i = 0; auto &value : vec)
    {
        value = static_cast<ValueType>(i);
        ++i;
    }
}

template <typename T>
void print_vector(const std::vector<T> &vec)
{
    for(std::size_t i = 0; const auto &value : vec)
    {
        std::cout << "Vec[" << i << "] = " << value << '\n';
    }
    std::cout << '\n';
}

int main(void)
{
    auto my_vector = std::vector<double>(3, 0.0);
    auto my_vector2 = std::vector<std::int32_t>(3, 0);
    auto my_vector3 = std::vector<char>(3, 97);

    print_vector(my_vector);
    fill_vector(my_vector);
    print_vector(my_vector);

    print_vector(my_vector2);
    fill_vector(my_vector2);
    print_vector(my_vector2);

    print_vector(my_vector3);
    fill_vector(my_vector3);
    print_vector(my_vector3);


    return 0;
}
