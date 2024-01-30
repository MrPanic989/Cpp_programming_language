#include <iostream>

#include "exercise.h"

int getDistance(void)
{
    int distance = 0;

    std::cout << "Please enter a distance: ";
    std::cin >> distance;

    return distance;
}

void mod_cross_sum(int I, int J)
{
    for(int i = 0; i < I; ++i)
    {
        for(int j = 0; j < J; ++j)
        {
            std::cout << "i: " << i << " , j: " << j << " := ";

            int sum = i + j;

            if(sum % 2 == 0)
            {
                std::cout << "Even!" << std::endl;
                continue;
            }

            std::cout << "Odd!" << std::endl;
        }
    }

}
