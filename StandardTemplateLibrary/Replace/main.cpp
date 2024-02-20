#include <iostream>
#include <cstdint>
#include <random>
#include <vector>
#include <chrono>
#include <algorithm>    //std::generate()

using ClockType = std::chrono::steady_clock;    //CPU computing time
using ClockRes = std::chrono::microseconds;  //Unit of time

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
    return value > 0;
}

int main(void)
{                                   //Initialization of 1000000 vectors with 0 as value
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0u);

    const auto start_time = ClockType::now();
    //std::generate generates new values
    std::generate(my_vector.begin(), my_vector.end(), gen);
    print_vector(my_vector);
                                        //replace every 0 with 1000
    std::replace(my_vector.begin(), my_vector.end(), 0, 1000);
    print_vector(my_vector);

    //Every function called as attribute for a something_if function, MUST return a bool!!
    //func1 returns in this case true, if the current value is greater than 0, and if so, we want
    //to replace it with the value 500
    std::replace_if(my_vector.begin(), my_vector.end(), func1, 500);
    print_vector(my_vector);

    const auto end_time = ClockType::now();
    const auto elapsed_time = std::chrono::duration_cast<ClockRes>(end_time - start_time).count();
    std::cout << "Elapsed time: " << elapsed_time << '\n';

    return 0;
}
