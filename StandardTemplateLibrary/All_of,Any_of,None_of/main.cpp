#include <iostream>
#include <cstdint>
#include <random>
#include <vector>
#include <algorithm>    //std::generate()

constexpr static auto NUM_ELEMENTS = 10u;

std::int32_t gen()
{
            //Generates a random Bit for the seed
    static auto seed = std::random_device{};   //Attention: some OS doesn't support this
    static auto gen = std::mt19937{seed()};    //Generates a rendom Bit based on the seed
                    //A rendom value from range -10 to 10, based on our generator
    static auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};
    //static, because we don't have to generate the random values every iteration, but just once
    //and then return one value per iteration

    return dist(gen);
}

void print_vector(const std::vector<std::int32_t> &vector)
{
    for(const auto &value : vector)
    {
        std::cout << value << " ";
    }
    std::cout << '\n';
}

bool func1(const std::int32_t value)
{
    return value > -5 && value < 5;
}

int main(void)
{                                   //Initialization of 1000000 vectors with 0 as value
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0u);

    //std::generate generates new values
    std::generate(my_vector.begin(), my_vector.end(), gen);
    print_vector(my_vector);

    const auto check1 = std::all_of(my_vector.begin(), my_vector.end(), func1);
    std::cout << "All of the values are greater than -5 and smaller than 5? " << std::boolalpha << check1 << '\n';

    const auto check2 = std::any_of(my_vector.begin(), my_vector.end(), func1);
    std::cout << "At least one value is greater than -5 and smaller than 5? " << std::boolalpha << check2 << '\n';

    const auto check3 = std::none_of(my_vector.begin(), my_vector.end(), func1);
    std::cout << "None of the values is greater than -5 and smaller than 5? " << std::boolalpha << check3 << '\n';

    return 0;
}
