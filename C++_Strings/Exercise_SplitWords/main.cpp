/*Implement the following functions:
- using WordCountPair = std::pair<std::string, std::size_t>;

- void clean_text(std::string &text);
    Replace the following characters with nothing: ['.', ',', '!', '?', '\n', '\t']

- void replace_all(std::string &text, std::string_view what, std::string_view with);
    Iterate over the string and replace all what entries with with

- std::vector<std::string> split_text(const std::string &text, char delimiter);
    Split the text on every word => One entry in the resulting vector is one word

Read in the text of the local text.txt file, the readFile is defined in the utils header:
#include "utils.hpp"

auto text = readFile("C:/Users/......../SplitWords/text.txt");

E.g. "Dolor sit vero" => ["Dolor", "sit", "vero"]
*/
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "Lib.hpp"
#include "utils.hpp"

int main()
{
    auto text = readFile("C:/Users/sinis/C++_programming_language/C++_Strings/Exercise_SplitWords/text.txt");
    std::cout << text << '\n' << '\n';

    clean_text(text);
    std::cout << text << '\n' << '\n';

    const auto splittedText = split_text(text, ' ');
    print_vector(splittedText);

    return 0;
}
