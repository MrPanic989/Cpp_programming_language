#include <iostream>

#include "Image.hpp"

int main(void)
{
    Image my_image1(100, 400);

    std::cout << "Image width: " << my_image1.get_width() << '\n';
    std::cout << "Image height: " << my_image1.get_height() << '\n';
    std::cout << "The matrix: " << static_cast<int>(my_image1.get_matrix()[0][0]) << '\n';
    my_image1.set_pixel(10, 10, 255);   //value range [0, 255]

    my_image1.save_image("image.bmp");

    return 0;
}
