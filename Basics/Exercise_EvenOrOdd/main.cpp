/*The task is to program the following function:
- void mod_cross_sum(int I, int J);

The task of the function is to iterate over a given running distance I and running distance J.
At each iteration it should be output whether the sum of the current i (for i in I) and j (for j in J)
is even or odd. That is, whether the result of (i + j) returns an even or odd number.

The function should be declared in the exercise.h file and defined in the
exercise.cc (or exercise.cpp) file.
*/
#include <iostream>

#include "exercise.h"

int main(void)
{
    int I = getDistance();
    int J = getDistance();

    mod_cross_sum(I, J);

    return 0;
}
