#include <iostream>
#include <tuple>
#include <utility> //for pair
#include <string>
#include <vector>

/*The biggest advantage of pair and tuple is that the elements
 they contain can be of different data types
*/
int main(void)
{
    auto my_pair = std::pair<int, float>{3431, -21.0f};
    std::cout << my_pair.first << '\n';
    std::cout << my_pair.second << '\n';

    auto my_tuple = std::tuple<int, float, std::string>{32, 3543.12f, "Mahony"};
    std::cout << std::get<0>(my_tuple) << '\n';
    std::cout << std::get<1>(my_tuple) << '\n';
    std::cout << std::get<2>(my_tuple) << '\n';

    const auto data = std::vector<std::pair<int, float>>{{23, 3232.2f}, {544, -32.0f}};
    for(const auto &d : data)
    {
        std::cout << d.first << ' ' << d.second << '\n';
    }

    return 0;
}
