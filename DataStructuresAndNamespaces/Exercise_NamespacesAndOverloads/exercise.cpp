#include <cstdint>

#include "exercise.hpp"

//If the functions are declared in a namespace, the definition has also to be in the namespace scope
namespace computation
{
    //return value is double because if you devide an integer number, the result may be
    //a float: 5 / 2 = 2.5
    double mean_array_value(int* array, const std::size_t length)
    {
        int sum = 0;

        for(std::size_t i = 0; i < length; ++i)
        {
            sum += array[i];
        }

        return sum / length;
    }

    double mean_array_value(double* array, const std::size_t length)
    {
        double sum = 0.0;

        for(std::size_t i = 0; i < length; ++i)
        {
            sum += array[i];
        }

        return sum / length;
    }

}
