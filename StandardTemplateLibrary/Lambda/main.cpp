#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

void print_vector(const std::vector<int> &vector)
{
    for(const auto &value : vector)
    {
        std::cout << value << " ";
    }
    std::cout << '\n';
}

bool check_even(const int value)
{
    return value % 2 == 0;
}

//lambda is usually used there, where we need a developed function just once
//otherwise we could just use our developed function
int main(void)
{
    auto my_vector = std::vector<int>(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);
    print_vector(my_vector);
    auto my_vector2 = my_vector;

    //transform without lambda
    auto my_result1 = std::vector<int>(10, 0);
    std::transform(my_vector.begin(), my_vector.end(), my_result1.begin(), check_even);
    print_vector(my_result1);

    //transform with lambda
    //A lambda function NEEDS a [](){}!!
    auto my_result2 = std::vector<int>(10, 0);
    std::transform(my_vector.begin(), my_vector.end(), my_result2.begin(),
                   [](const auto value){return value % 2 == 0;});
    print_vector(my_result2);

    //copy_if
    auto my_result3 = std::vector<int>{};           //Because we don't know the lengtz of my_result 3, we
                                                    //have to push the value back every iteration
    std::copy_if(my_vector.begin(), my_vector.end(), std::back_inserter(my_result3),
                 [](const auto value){return value % 2 == 0;}); //copy_if the lambda result is true
    print_vector(my_result3);

    //VERSION 1:delete elements. Everi function with _if expects from lambda a boolean value
    my_vector.erase(std::remove_if(my_vector.begin(), my_vector.end(),
                                   [](const auto value){return value > 5;}),
                    my_vector.end());
    print_vector(my_vector);
    //VERSION 2: when we want to use a variable defined out of the lambda scope
    // =: copy
    // &: reference
    const auto upper_bound = 3;
    my_vector.erase(std::remove_if(my_vector.begin(), my_vector.end(),
                                   [=](const auto value){return value > upper_bound;}),
                    my_vector.end());
    print_vector(my_vector);

    //replace_if:
    const auto search_value = 2;
    const auto replace_value = 42;
    std::replace_if(my_vector.begin(), my_vector.end(),
                    [=](const auto value){return value == search_value;},
                    replace_value);
    print_vector(my_vector);

    //sort:
    auto sorting = [](const auto left, const auto right){return left > right;};
    std::sort(my_vector2.begin(), my_vector2.end(), sorting);
    print_vector(my_vector2);

    return 0;
}
