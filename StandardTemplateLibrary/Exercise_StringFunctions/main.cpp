/*Implement the following functions:
    namespace mystd
    {

    bool is_palindrom(std::string_view str);

    bool starts_with(std::string_view str, std::string_view substr);

    bool ends_with(std::string_view str, std::string_view substr);

    bool contains(std::string_view str, std::string_view substr);

    std::size_t num_occurences(std::string_view str, std::string_view substr);

    } // namespace mystd

is_palindrom:
    Check if the string is a palindrome
    E.g. "anna" is a palindrome since the reversed string is the same.

starts_with:
    Check if the string starts with the substring

ends_with:
    Check if the string ends with the substring

contains:
    Check if the string contains the substring

num_occurences:
    Count how many times the substring is in the string

Note: main.cpp is given
*/
#include <cassert>
#include <iostream>
#include <string>

#include "lib.hpp"

void test_cases();

int main()
{
    std::string str1 = "anna";
    std::cout <<  str1 << " is_palindrom: " << std::boolalpha << mystd::is_palindrom(str1) << '\n';

    std::string str2 = "JanIstHier";
    std::cout  << str2 << " starts w/ Jan = " << std::boolalpha << mystd::starts_with(str2, "Jan") << '\n';
    std::cout  << str2 << " starts w/  Ja = " << std::boolalpha << mystd::starts_with(str2, "Ja") << '\n';
    std::cout  << str2 << " starts w/  ja = " << std::boolalpha << mystd::starts_with(str2, "ja") << '\n';

    std::string str3 = "JanWarHier";
    std::cout  << str3 << " ends w/ Hier = " << std::boolalpha << mystd::ends_with(str3, "Hier") << '\n';
    std::cout << std::boolalpha << str3 << " ends w/ Hie = " << mystd::ends_with(str3, "Hie") << '\n';
    std::cout << std::boolalpha << str3 << " ends w/ Hir = " << mystd::ends_with(str3, "Hir") << '\n';

    std::string str4 = "JanWarHier";
    std::cout << std::boolalpha << str4 << " contains: Hier = " << mystd::contains(str4, "Hier") << '\n';
    std::cout << std::boolalpha << str4 << " contains: War = " << mystd::contains(str4, "War") << '\n';
    std::cout << std::boolalpha << str4 << " contains: jan = " << mystd::contains(str4, "jan") << '\n';

    std::string str5 = "HalloHallohaHallo";
    std::cout << "occurences: " << mystd::num_occurences(str5, "Hallo") << '\n';

    test_cases();

    return 0;
}

void test_cases()
{
    assert(mystd::is_palindrom("anna") == true);
    assert(mystd::is_palindrom("aNna") == false);

    assert(mystd::ends_with("anna", "a") == true);
    assert(mystd::ends_with("anna", "na") == true);
    assert(mystd::ends_with("anna", "ann") == false);

    assert(mystd::starts_with("anna", "a") == true);
    assert(mystd::starts_with("anna", "na") == false);
    assert(mystd::starts_with("anna", "ann") == true);

    assert(mystd::contains("anna", "ann") == true);
    assert(mystd::contains("anna", "nn") == true);
    assert(mystd::contains("anna", "nna") == true);
    assert(mystd::contains("anna", "ana") == false);

    assert(mystd::num_occurences("anna", "a") == 2);
    assert(mystd::num_occurences("anna", "n") == 2);
    assert(mystd::num_occurences("anna", "nn") == 1);
    assert(mystd::num_occurences("anna", "anna") == 1);
    assert(mystd::num_occurences("anna", "annaa") == 0);
}
