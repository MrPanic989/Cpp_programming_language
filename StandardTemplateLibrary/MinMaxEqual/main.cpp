#include <iostream>
#include <cstdint>
#include <random>
#include <vector>
#include <algorithm>    //std::generate(), std::equal(), std::min_element(), std::max_element()

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

/*
struct  Data
{
    std::int32_t v1;
    std::int32_t v2;
};

bool compare(const Data &i, const Data &j)
{
    return i.v1 < j.v1 && i.v2 < j.v2;
}
*/

int main(void)
{                                   //Initialization of 1000000 vectors with 0 as value
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0u);

    //std::generate generates new values
    std::generate(my_vector.begin(), my_vector.end(), gen);
    print_vector(my_vector);

    //Instead of a for-loop
    //not to be confused with min() which takes only 2 elements. min_element() iterates through an array
    const auto min = std::min_element(my_vector.begin(), my_vector.end());
    const auto max = std::max_element(my_vector.begin(), my_vector.end());
    std::cout << "Min: " << *min << '\n' << "Max: " << *max << '\n';

    /*Version where the algorithm isn't predefined, e.g. structs
    auto my_struct_vector = std::vector<Data>{Data{0, 0}, Data{-1, 1}};
    const auto min_struct = std::min_element(my_struct_vector.begin(), my_struct_vector.end(), compare);
    const auto max_struct = std::max_element(my_struct_vector.begin(), my_struct_vector.end(), compare);
    */

    auto my_vector2 = my_vector;
    const auto equal = std::equal(my_vector.begin(), my_vector.end(), my_vector2.begin());
    std::cout << "Equal? " << std::boolalpha << equal << '\n';

    return 0;
}
