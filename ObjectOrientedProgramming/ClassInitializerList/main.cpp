#include <iostream>

#include "Image.hpp"

int main(void)
{
    Image my_image1(100, 400);
    my_image1.save_image("image.bmp");


    return 0;
}
