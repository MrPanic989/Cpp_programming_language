#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main()
{
    const auto my_vector = std::vector{0, 1, 2, 3, 4, 5};   //If we know the values, we should initialize
    auto my_result = std::vector<int>{};        //if we don't know the values at the start
                                                //then we need a data type <> and curly brackets
    auto my_result2 = std::list<int>{};

    // container must implement "insert"
    std::copy(my_vector.begin(),
              my_vector.end(),
              std::inserter(my_result, my_result.end()));
    for (const auto val : my_result)
        std::cout << val << " ";
    std::cout << '\n';
    my_result.clear();

    // container must implement "push_back"
    std::copy(my_vector.begin(),
              my_vector.end(),
              std::back_inserter(my_result));
    for (const auto val : my_result)
        std::cout << val << " ";
    std::cout << '\n';
    my_result.clear();

    // container must implement "push_front", which is a list
    std::copy(my_vector.begin(),
              my_vector.end(),
              std::front_inserter(my_result2));
    for (const auto val : my_result2)
        std::cout << val << " ";
    std::cout << '\n';
    my_result2.clear();

    return 0;
}
