/*Implement the following functions:
    namespace mystd
    {

    using Container = std::vector<std::int32_t>;
    using Iterator = Container::iterator;

    bool equal(Iterator first1, Iterator last1, Iterator first2);

    Iterator fill_n(Iterator first, std::size_t count, const std::int32_t &value);

    void iota(Iterator first, Iterator last, std::int32_t value);

    Iterator copy(Iterator first, Iterator last, Iterator d_first);

    std::int32_t accumulate(Iterator first, Iterator last, std::int32_t init);

    } // namespace mystd
equal:
Return true if all elements of both vectors are the same

fill_n:
Fill the vector n times with the value 'value' within the range [first, last]

iota:
Fill the vector with incrementing the value 'value' within the range [first, last]

copy:
Copy the elements from one vector to the other vector

accumulate:
Compute the sum of the vector within the range [first, last]

Note: the main.cpp is given.
*/
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

#include "lib.hpp"
#include "utils.hpp"

void test_cases();

int main()
{
    auto vec1 = std::vector<std::int32_t>(5, 0);
    auto vec2 = std::vector<std::int32_t>(5, 0);
                                                //from where to where    //with what
    std::cout << std::boolalpha << mystd::equal(vec1.begin(), vec1.end(), vec2.begin()) << '\n';
                //where //how many times //what value
    mystd::fill_n(vec1.begin(), 5, 1);
    print_vector(vec1);

    mystd::iota(vec2.begin(), vec2.end(), 0);
    print_vector(vec2);
    std::cout << std::boolalpha << mystd::equal(vec1.begin(), vec1.end(), vec2.begin()) << '\n';

    mystd::copy(vec2.begin(), vec2.end(), vec1.begin());
    std::cout << std::boolalpha << mystd::equal(vec1.begin(), vec1.end(), vec2.begin()) << '\n';

    const auto sum = mystd::accumulate(vec1.begin(), vec1.end(), 0);
    std::cout << sum << '\n';

    test_cases();

    return 0;
}

void test_cases()
{
    auto vec1 = std::vector<std::int32_t>(5, 0);
    auto vec2 = std::vector<std::int32_t>(5, 0);
    auto vec3 = std::vector<std::int32_t>(5, 0);
    vec3.back() = 1;

    assert(mystd::equal(vec1.begin(), vec1.end(), vec2.begin()) == true);
    assert(mystd::equal(vec1.begin(), vec1.end(), vec3.begin()) == false);

    mystd::fill_n(vec1.begin(), 5, 1);
    mystd::fill_n(vec2.begin(), 5, 1);
    assert(mystd::equal(vec1.begin(), vec1.end(), vec2.begin()) == true);

    mystd::copy(vec1.begin(), vec1.end(), vec3.begin());
    assert(mystd::equal(vec1.begin(), vec1.end(), vec3.begin()) == true);

    assert(mystd::accumulate(vec1.begin(), vec1.end(), 0) == 5);
}
