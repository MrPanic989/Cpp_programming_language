#include <iostream>
#include <cstdint>

int32_t getNumber(void)
{
    int32_t number = 0;
    std::cout << "Please enter a number: ";
    std::cin >> number;

    return number;
}

bool isNumberEven(int32_t input)
{
    if(input % 2 == 0)
    {
        return true;
    }

    return false;
}

int main(void)
{
    int32_t user_number = getNumber();
    std::cout << "Your number is: " << user_number << std::endl;

    std::cout << "Is the your number even? " << std::boolalpha << isNumberEven(user_number) << std::endl;

    return 0;
}
