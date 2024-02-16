/*Implement the following functions:
- using It = std::vector<std::int32_t>::iterator;
- using DifferenceType = It::difference_type;
- void advance(It &it, DifferenceType n);
    Step n-steps to the right (forward) with the iterator

- DifferenceType distance(It first, It last);
    Compute the distance between two iterators of the same container

- It next(It it, DifferenceType n = 1);
    Step 1-step to the right (forward) with the iterator
    Note: 1-step is the default value for the parameter n

- It prev(It it, DifferenceType n = 1);
    Step 1-step to the left (backward) with the iterator
    Note: 1-step is the default value for the parameter n
*/
#include <iostream>
#include <vector>
#include <cassert>

#include "Lib.hpp"

void test_cases();

int main()
{
    auto vec = std::vector<int>{1, 2, 3};
    auto vec_it = vec.begin();

    const auto next_it = mystd::next(vec_it);
    std::cout << "*next_it: " << *next_it << '\n';

    const auto prev_it = mystd::prev(next_it);
    std::cout << "*prev_it: " << *prev_it << '\n';

    mystd::advance(vec_it, 2);
    std::cout << "advance: " << *vec_it << '\n';

    const auto dist = mystd::distance(vec_it, vec.end());
    std::cout << "distance: " << dist << '\n';

    test_cases();

    return 0;
}

void test_cases()
{
    auto vec = std::vector<std::int32_t>{2, 1, -2, 0, -1};

    const auto next_it = mystd::next(vec.begin());
    assert(next_it == vec.begin() + 1);
    const auto prev_it = mystd::prev(next_it);
    assert(prev_it == vec.begin());

    auto it = vec.begin();
    mystd::advance(it, 0);
    assert(it == vec.begin());
    mystd::advance(it, 2);
    assert(it == vec.begin() + 2);
    mystd::advance(it, -2);
    assert(it == vec.begin());

    const auto next_it2 = mystd::next(it, 3);
    assert(next_it2 == vec.begin() + 3);
    const auto prev_it2 = mystd::prev(it, 3);
    assert(prev_it2 == vec.begin());

    assert(mystd::distance(prev_it2, vec.begin()) == 0);
    assert(mystd::distance(vec.begin(), vec.end()) == vec.size());
}
