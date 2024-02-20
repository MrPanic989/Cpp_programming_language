/*We have a binary random vector "target" in the main function, with a length of 20 elements.
Its values have already been randomly permuted and saved in a new vector “input”.

Task 1:
Writes a function
    - vector<bool> shuffle_till_equal(const BinaryArray &target, BinaryArray input);
Which accepts a binary vector “target” and a binary vector “input”. At each iteration it is
necessary to check whether the two vectors have the same values. If this is the case,
the function can terminate. If this is not the case, the (entire) input array should be shuffled again.

Task 2:
Now we want to program a more efficient version.
    - vector<bool> smart_shuffle_till_equal(const BinaryArray &target, BinaryArray input);
This should not always shuffle the entire vector, but only from the index where the first different
value appears. (Seen from the beginning of the vector)
Execute this function and also measures the time.
*/
#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

#include "exercise.hpp"

using ClockType = std::chrono::high_resolution_clock;

int main()
{
    auto gen = std::random_device{};
    auto dist = std::bernoulli_distribution(0.5);

    auto target = BinaryArray(10, false);
    std::generate(target.begin(), target.end(), [&] { return dist(gen); });

    auto input = BinaryArray(target.begin(), target.end());
    std::shuffle(input.begin(), input.end(), std::default_random_engine{42});

    for (std::size_t i = 0; i < target.size(); ++i)
    {
        std::cout << "Target[" << i << "] = " << target[i] << '\n';
    }
    for (std::size_t i = 0; i < input.size(); ++i)
    {
        std::cout << "Input[" << i << "] = " << input[i] << '\n';
    }

    ////// START EXERCISES

    // Exercise 1
    std::cout << '\n' << "Starting exercise 1";
    auto start = ClockType::now();
    const auto result_exercise1 = shuffle_till_equal(target, input);
    auto end = ClockType::now();
    auto elapsed_milliseconds =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
            .count() /
        1000.0;
    std::cout << '\n' << "Time for exercise 1 in ns: " << elapsed_milliseconds;
    const auto is_equal2 = std::equal(result_exercise1.begin(),
                                      result_exercise1.end(),
                                      target.begin());
    std::cout << '\n' << "Vectors are equal: " << is_equal2 << '\n';

    // Exercise 2
    std::cout << '\n' << "Starting exercise 2";
    start = ClockType::now();
    const auto result_exercise2 = smart_shuffle_till_equal(target, input);
    end = ClockType::now();
    elapsed_milliseconds =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
            .count() /
        1000.0;
    std::cout << '\n' << "Time for exercise 2 in ns: " << elapsed_milliseconds;
    const auto is_equal3 = std::equal(result_exercise2.begin(),
                                      result_exercise2.end(),
                                      target.begin());
    std::cout << '\n' << "Vectors are equal: " << is_equal3 << '\n';

    return 0;
}
