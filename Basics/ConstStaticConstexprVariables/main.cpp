#include <iostream>
#include <cstdint>
#include <cmath>

/*In the modern C++ programming you should always use constexpr commands instead of
defines. The only legitime case where you should use defines is, when you explicitly
want to lock or unlock a partial code.
*/
#define NUM_PLAYERS 2
#define MODE_1

//Perfect example of usage of the constexpr variable, the GLOBAL variables. It's like natural law, cannot be changed.
//With keyword 'static' we assure that it is saved in memory.
constexpr static float PI = 3.14159265359;

float func(const float val)
{   //read/write variable
    static int counter = 0;     //static variables are saved in the static memory and don't lose their
    counter++;                  //memory after the end of the function

    if(counter <= 3)
    {   //read only variable
        const float temp = val * 2.0f;  //const variables must be deklared and initialized at the same time
                                    //const keywords are created in the "Runtime"
                                    //After a const variable is initialized, its value cannot be changed
        return temp / 3.0f;
    }

    return 0;
}

int main(void)
{
    std::uint32_t num_players = 5u;     //read/write variable

    constexpr float v = 2.0f * 23.4f * 5.3f;    /*constexpr keywords are created during the "Compiletime",
    that means that when we run our program, the result of this variable would be already available. It
    can only be created with hardcoded values: constexpr float v = a * 2.0f * 3.4f is not allowed.*/

    std::cout << func(v) << '\n';
    std::cout << func(v) << '\n';
    std::cout << func(v) << '\n';
    std::cout << func(v) << '\n';

#ifdef MODE_1
    std::cout << "Num Players: " << NUM_PLAYERS << std::endl;
#else
    //This line doesn't exist if MODE_1 is activated! Not even the compiler registers it!
    std::cout << "Num Players: " << num_players << std::endl;
#endif

    /*Casting:
    - C style: (newDatatype)(varName);
    - C++ style (and what we should use): static_cast<newDatatype>(varName);
    */
    std::uint8_t value = 143u;
    std::cout << "The binary representation of value is: ";
    for(int8_t i = 7; i >= 0; --i)
    {
        /*Keyword 'auto': we let the compiler decide for itself what kind of
        data type the variable is. You should usually use it only for casting,
        to prevent confusions.
        auto a = 12u; -> a is an unsigned int
        auto b = 143; -> b is an integer
        auto c = 23.5f; -> c is a float
        auto d = 453.3; -> d is a double
        */
        auto current_exponent = static_cast<std::uint8_t>(std::pow(2, i));

        if(current_exponent <= value)
        {
            std::cout << "1 ";
            value -= current_exponent;
        }
        else
        {
            std::cout << "0 ";
        }
    }
    std::cout << "\n";


    /*UNIFORM INITIALIZATION:
    auto k = double{5.0};
    -Variant 1:
        auto l = int{k};    -> Compile -> warning: narrowing conversion of 'k' from 'double' to 'int'

    -Variant 2:
        int m = k;      -> Compile -> no warning.

    Uniform initialization (variant 1) therefore is better, because it warns us and prevents us
    from errors.
    */

    return 0;
}
