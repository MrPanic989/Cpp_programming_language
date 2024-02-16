#include <iostream>
#include <map>
#include <cstdint>
#include <string>

//map == hashtable
int main(void)
{
    auto my_map = std::map<std::string, std::uint32_t>{};
    my_map["Jan"] = 28;
    my_map["Dennis"] = 31;
    my_map["Lisa"] = 33;

    for(const auto &val : my_map)
    {
        std::cout << val.first << ' ' << val.second << '\n';
    }

    std::cout << my_map["Dennis"] << '\n';  //31

    //C++17
    auto search_str = "Jan";
    const auto search_it = my_map.find(search_str); //When using find() always search for the key, not value
    bool found_key = search_it != my_map.end();

    std::cout << std::boolalpha << found_key << '\n';

    //C++20
    //bool found_key2 = my_map.contains(search_str);


    return 0;
}
