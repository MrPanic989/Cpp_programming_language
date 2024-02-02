#include <iostream>
#include <cstdint>

#include "lib.hpp"

bool is_numeric(const char character)
{
    if(character >= '0' && character <= '9')
    {
        return true;
    }

    return false;
}

bool is_alpha(const char character)
{
    if(is_lower_case(character) || is_upper_case(character))
    {
        return true;
    }

    return false;
}

bool is_alpha_numeric(const char character)
{
    if(is_numeric(character) || is_alpha(character))
    {
        return true;
    }

    return false;
}

bool is_upper_case(const char character)
{
    if(character >= 'A' && character <= 'Z')
    {
        return true;
    }

    return false;
}

bool is_lower_case(const char character)
{
    if(character >= 'a' && character <= 'z')
    {
        return true;
    }

    return false;
}

char to_upper_case(const char character)
{
    char letter = character;

    if(is_lower_case(character))
    {
        letter -= 32;
    }

    return letter;
}

char to_lower_case(const char character)
{
    char letter = character;

    if(is_upper_case(character))
    {
        letter += 32;
    }

    return letter;
}

char* to_upper_case(char* text)
{
    if(text == nullptr)
    {
        return nullptr;
    }

    std::uint32_t idx = 0u;

    while(text[idx] != '\0')
    {
        text[idx] = to_upper_case(text[idx]);
        ++idx;
    }

    return text;
}

char* to_lower_case(char* text)
{
    if(text == nullptr)
    {
        return nullptr;
    }

    std::uint32_t idx = 0u;

    while(text[idx] != '\0')
    {
        text[idx] = to_lower_case(text[idx]);
        ++idx;
    }

    return text;
}

std::size_t string_length(const char* text)
{
    if(text == nullptr)
    {
        return 1;
    }

    std::size_t size = 0;

    while(*text != '\0')
    {
        ++size;
        ++text;
    }

    return size;
}

bool string_equal(const char* string1, const char* string2)
{
    if((string1 == nullptr || string2 == nullptr) || (string_length(string1) != string_length(string2)))
    {
        return false;
    }

    std::uint32_t idx = 0u;

    while(string1[idx] != '\0')
    {
        if(string1[idx] != string2[idx])
        {
            return false;
        }
        ++idx;
    }

    return true;
}
