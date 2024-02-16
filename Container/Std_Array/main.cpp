#include <iostream>
#include <array>
#include <vector>

constexpr static auto ARRAY_LEN = 3u;    //Usually if you plan to use the variable several times in your code

int main(void)
{
    /*The only difference between std::array and std::vector is that with array you don't
    have the two very handy functions push() and pop() because we can't dynamically change an array.
    This is only possible with a vector.
    */
    const auto vec = std::vector<int>{1, 2, 3};
    const auto arr = std::array<int, ARRAY_LEN>{4, 5, 6};

    std::cout << vec.size() << '\n';
    std::cout << arr.size() << '\n';

    std::cout << std::boolalpha << vec.empty() << '\n';
    std::cout << std::boolalpha << arr.empty() << '\n';

    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    for(auto it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    //foreach loop - C++ style
    for(const auto val : vec)
    {
        std::cout << val << ' ';
    }
    std::cout << '\n';
    for(const auto val : arr)
    {
        std::cout << val << ' ';
    }
    std::cout << '\n';

    return 0;
}
