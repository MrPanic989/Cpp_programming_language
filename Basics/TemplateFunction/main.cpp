#include <iostream>
#include <cstdint>

/*Feature of the C++ language: function overload, a valid C++ Code!
For function overload to be valid, at least one of the parameters has to be different
than those of the other function with the same name. But function overload is normally used,
when the function body is also different than the body of the other function.
double max(double a, double b)
{
    return a > b ? a : b;
}

int32_t max(int32_t a, int32_t b)
{
    return a > b ? a : b;
}
*/

/*If the function body is however identical as the body of another function with the same name,
there is a different tool in C++ you can use: the Template Function!
*/
template <typename Type>
Type max(Type a, Type b)
{
    return a > b ? a : b;
}


int main(void)
{
    double da = 1.0;
    double db = 3.0;
    std::cout << max(da, db) << std::endl;

    int32_t ia = 1;
    int32_t ib = 4;
    std::cout << max(ia, ib) << std::endl;

    return 0;
}
