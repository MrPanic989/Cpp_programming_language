#include <iostream>
#include <list>
#include <vector>

/*A list is very practical if you want to add or remove elements frequently,
since the nodes all know who their predecessor and successor are and
they are not located contiguously in memory, as it is the case with arrays and vectors.
But, for example, if we want to access the 5000th element, we MUST visit all
4999 previous elements, which is not very practical. For a vector it is simply vec[5000]
*/
int main(void)
{
    const auto vec = std::vector<int>{1, 2, 3};
    const auto lst = std::list<int>{4, 5, 6};

    std::cout << vec.size() << '\n';
    std::cout << lst.size() << '\n';

    std::cout << std::boolalpha << vec.empty() << '\n';
    std::cout << std::boolalpha << lst.empty() << '\n';

    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    for(auto it = lst.begin(); it != lst.end(); ++it)
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
    for(const auto val : lst)
    {
        std::cout << val << ' ';
    }
    std::cout << '\n';

    for(std::size_t i = 0; i < 3; ++i)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';

    auto it_list = lst.begin();
    for(std::size_t i = 0; i < 3; ++i)
    {
        std::cout << *it_list << ' ';
        ++it_list;
    }
    std::cout << '\n';

    return 0;
}
