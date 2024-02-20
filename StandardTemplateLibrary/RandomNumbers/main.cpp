#include <iostream>
#include <cstdint>
#include <random>
#include <vector>

constexpr static auto NUM_ELEMENTS = 1000000u;

int main(void)
{                                   //Initialization of 1000000 vectors with 0 as value
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0u);

            //Generates a random Bit for the seed
    auto seed = std::random_device{};   //Attention: some OS doesn't support this
    auto gen = std::mt19937{seed()};    //Generates a rendom Bit based on the seed
                    //A rendom value from range -10 to 10, based on our generator
    auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};

    for(std::size_t i = 0; i < my_vector.size(); ++i)
    {
        my_vector[i] = dist(gen);
    }

    for(std::size_t i = 0; i < 20u; ++i)
    {
        std::cout << my_vector[i] << '\n';
    }

    return 0;
}
