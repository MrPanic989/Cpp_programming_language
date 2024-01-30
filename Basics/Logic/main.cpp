#include <iostream>
#include <cstdint>

int main(void)
{
    int32_t number = 0;
    std::cout << "Please enter your guess (only numbers from 0 to including 10): ";
    std::cin >> number;

    int32_t absolute_nr = number;

    if(number < 0)
    {
        absolute_nr = -1 * number;
    }

    std::cout << "Abs(" << number << ") = " << absolute_nr << std::endl;

    bool check = ((absolute_nr >= 0) && (absolute_nr <= 10));
    std::cout << "Check: " << std::boolalpha << check << std::endl;     //boolalpha prints the value in words: true or false

    if(check)
    {
        if(absolute_nr == 4)
        {
            std::cout << "You have won!" << std::endl;
        }
        else if (absolute_nr % 2 == 0)       //if it's an even number
        {
            std::cout << "You have won a wooden spoon!" << std::endl;
        }
        else
        {
            std::cout << "You have lost!" << std::endl;
        }

    }
    else
    {
        std::cout << "You have entered an invalid number!" << std::endl;
    }

    return 0;
}
