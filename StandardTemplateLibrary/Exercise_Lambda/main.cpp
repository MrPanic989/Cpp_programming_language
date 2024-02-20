/*In this programming exercise, lambda expressions should be used in all tasks. All the code
is given in the Lambda.cpp file (inside the Main function). We will use the vector my_vector
and my_result to carry out the upcoming tasks.

- Task 1:
Check the vector my_vector to see whether it contains any even values and print the result
in the console.
    bool has_no_even = ...;
    if(has_no_even)
    {
        std::cout << "None of the vector values are even" << std::endl;
    }
    else
    {
        std::cout << "The vector has even numbers" << std::endl;
    }

- Task 2;
Save the squared values of my_vector in my_result and print them in the console.
    ... // Square the values

    for (const auto &val : my_result)
    {
        std::cout << val << std::endl;
    }
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

std::int32_t gen()
{
    static auto seed = std::random_device{};
    static auto gen = std::mt19937{seed()};
    static auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};

    return dist(gen);
}

int main()
{
    auto my_vector = std::vector<int>(10, 0);
    std::generate(my_vector.begin(), my_vector.end(), gen);

    auto my_result = std::vector<int>(10, 0);

    for(const auto &val : my_vector)
    {
        std::cout << val << '\n';
    }
    std::cout << '\n';

    // Exercise 1
    const auto has_no_even = std::none_of(my_vector.begin(), my_vector.end(),
                                        [](const auto value) {return (value % 2 == 0);}
                                         );

    if(has_no_even)
    {
        std::cout << "None of the vector values are even" << '\n';
    }
    else
    {
        std::cout << "The vector has even numbers" << '\n';
    }
    std::cout << '\n';

    // Exercise 2
    std::transform(my_vector.begin(), my_vector.end(), my_result.begin(),
                   [](const auto value) {return static_cast<int>(std::pow(value, 2.0));}
                   );

    for(const auto &val : my_result)
    {
        std::cout << val << '\n';
    }

    return 0;
}
