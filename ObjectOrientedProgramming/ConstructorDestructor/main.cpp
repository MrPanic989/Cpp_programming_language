#include <iostream>

#include "Image.hpp"

int main(void)
{
    std::cout << "Line 7\n";
    {
        Image my_image1(10, 10);    //This object has a scope now
    }
    std::cout << "Line 11\n";   //From this line, the object my_image1 doesn't exist (out of scope)

    return 0;
}
