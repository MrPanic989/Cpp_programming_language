#include <algorithm>

#include "lib.hpp"

namespace mystd
{

bool is_palindrom(std::string_view str)
{
    /*
    const auto copy = std::string(str.begin(), str.end());
    return str == copy;
    */

    return std::equal(str.begin(), str.end(), str.rbegin());
}

bool starts_with(std::string_view str, std::string_view substr)
{
    return std::equal(substr.begin(), substr.end(), str.begin());
}

bool ends_with(std::string_view str, std::string_view substr)
{
    return std::equal(substr.rbegin(), substr.rend(), str.rbegin());
}

bool contains(std::string_view str, std::string_view substr)
{
    const auto substr_length = substr.length();
                                    //end - length to ensure not falling out of the valid range
    for(auto it = str.begin(); it < str.end() - substr_length + 1;)
    {
        /*string = abcdef, sub = cd
        starting from a: found = cd compare with ab -> false -> iterator moved to b
        we continue now with b: found = cd compare with bc -> false -> iterator moves to c
        we continue now with c: found = cd compare with cd -> true -> break the loop and return value true
        */
        const auto found = std::equal(substr.begin(), substr.end(), it);

        if(found == true)
        {
            return true;
        }

        ++it;
    }

    return false;
}

std::size_t num_occurences(std::string_view str, std::string_view substr)
{
    auto result = std::size_t{0};
    const auto substr_length = substr.length();

    for(auto it = str.begin(); it < str.end() - substr_length + 1;)
    {
        auto found = std::equal(substr.begin(), substr.end(), it);

        if (found == true)
        {
            ++result;
        }

        ++it;
    }

    return result;
}

} // namespace mystd
