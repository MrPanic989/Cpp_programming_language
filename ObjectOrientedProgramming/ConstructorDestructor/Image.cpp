#include <iostream>

#include "Image.hpp"

//namescope //method
Image::Image(const std::uint32_t width, const std::uint32_t height)
{
    this->m_width = width;      //Better solution: use class initializer list!!
    this->m_height = height;

    std::cout << "Image object created with shape: widht = " << width << ", height = " << height << "!\n";
}

Image::~Image()
{
    std::cout << "Image object destroyed!\n";
}
