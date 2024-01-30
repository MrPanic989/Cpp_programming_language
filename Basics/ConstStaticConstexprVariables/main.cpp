#include <iostream>
#include <cstdint>

constexpr float PI = 3.14159265359; //Perfect example of usage of the constexpr variable. It's like natural law.

float func(const float val)
{
    static int counter = 0;     //static variables are saved in the static memory and don't lose their
    counter++;                  //memory after the end of the function

    if(counter <= 3)
    {
        const float temp = val * 2.0f;  //const variables must be deklared and initialized at the same time
                                    //const keywords are created in the "Runtime"
                                    //After a const variable is initialized, its value cannot be changed
        return temp / 3.0f;
    }

    return 0;
}

int main(void)
{
    constexpr float v = 2.0f * 23.4f * 5.3f;    /*constexpr keywords are created during the "Compiletime",
    that means that when we run our program, the result of this variable would be already available. It
    can only be created with hardcoded values: constexpr float v = a * 2.0f * 3.4f is not allowed.*/

    std::cout << func(v) << '\n';
    std::cout << func(v) << '\n';
    std::cout << func(v) << '\n';
    std::cout << func(v) << '\n';

    return 0;
}
