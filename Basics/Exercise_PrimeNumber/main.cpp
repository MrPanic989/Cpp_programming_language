#include <iostream>
#include <cstdint>

int main(void)
{
    uint32_t input = 0u;
    std::cout << "Please enter an positive number: ";
    std::cin >> input;

    bool is_prime = true;

    if(input == 0u || input == 1u)
    {
        is_prime = false;
    }
              //Algorithm for prime nr          //E.g. input = 29;                      //E.g. input = 15
    for(uint32_t i = 2; i * i <= input; ++i)    //i = 2; 2 * 2 <= 29 -> 29 % 2 != 0     //i = 2; 2 * 2 <= 15 -> 15 % 2 != 0
    {                                           //i = 3; 3 * 3 <= 29 -> 29 % 3 != 0     //i = 3; 3 * 3 <= 15 -> 15 % 3 = 0 -> is_prime = false;
        if(input % i == 0)                      //i = 4; 4 * 4 <= 29 -> 29 % 4 != 0
        {                                       //i = 5; 5 * 5 <= 29 -> 29 % 5 != 0
            is_prime = false;                   //i = 6; 6 * 6 > 29, break
        }
    }

    std::cout << "Is it true, that the number " << input << "is a prime number? It is " << std::boolalpha << is_prime << std::endl;

    return 0;
}
