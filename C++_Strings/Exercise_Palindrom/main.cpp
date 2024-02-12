/*Is a string also a palindrom?
*/
#include <iostream>
#include <string>
#include <string_view>

bool is_palindrom(const std::string &text)
{       //Temporary string with reversed letter order (from end to begin) of origin string
    const auto reversed = std::string(text.rbegin(), text.rend());

    return text == reversed;
}

int main(void)
{
    const auto text = std::string{"anna"};
    const auto check = is_palindrom(text);

    std::cout << "Is Palindrome: " << std::boolalpha << check << '\n';

    return 0;
}
