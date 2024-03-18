#include <iostream>

#include "Image.hpp"

//namescope //method
Image::Image(const std::uint32_t width, const std::uint32_t height)
    //class initializer list        //vector of vectors(how many, what-in our case vectors that
    //row of class members          //represent gray scales). If we construct a object Image m(10, 5)
    //is very important             //we are creating 10 vectors that saves 5 times the value 0, which is black
                                    //So in total, we create a 10x5 picture, that is, 50 pixels
    : m_width(width), m_height(height), m_matrix(m_width, std::vector<std::uint8_t>(m_height, 0))
{
    std::cout << "Image object created with shape: widht = " << width << ", height = " << height << "!\n";
    std::cout << m_matrix.size() << '\n';
}

Image::~Image()
{
    std::cout << "Image object destroyed!\n";
}

//Imported function
void Image::save_image(const char* file_name) const
{
    FILE* f = nullptr;

    auto num_bytes = 3 * m_width * m_height;
    auto *img = new std::uint8_t[num_bytes]{};

    auto filesize = 54 + 3 * m_width * m_height;

    for (std::uint32_t x = 0; x < m_width; ++x)
    {
        for (std::uint32_t y = 0; y < m_height; y++)
        {
            img[(x + y * m_width) * 3 + 2] = m_matrix[x][y] % 256;
            img[(x + y * m_width) * 3 + 1] = m_matrix[x][y] % 256;
            img[(x + y * m_width) * 3 + 0] = m_matrix[x][y] % 256;
        }
    }

    std::uint8_t
        bmpfileheader[14]{'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    std::uint8_t
        bmpinfoheader[40]{40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    std::uint8_t bmppad[3]{0, 0, 0};

    bmpfileheader[2] = static_cast<std::uint8_t>(filesize);
    bmpfileheader[3] = static_cast<std::uint8_t>(filesize >> 8);
    bmpfileheader[4] = static_cast<std::uint8_t>(filesize >> 16);
    bmpfileheader[5] = static_cast<std::uint8_t>(filesize >> 24);

    bmpinfoheader[4] = static_cast<std::uint8_t>(m_width);
    bmpinfoheader[5] = static_cast<std::uint8_t>(m_width >> 8);
    bmpinfoheader[6] = static_cast<std::uint8_t>(m_width >> 16);
    bmpinfoheader[7] = static_cast<std::uint8_t>(m_width >> 24);
    bmpinfoheader[8] = static_cast<std::uint8_t>(m_height);
    bmpinfoheader[9] = static_cast<std::uint8_t>(m_height >> 8);
    bmpinfoheader[10] = static_cast<std::uint8_t>(m_height >> 16);
    bmpinfoheader[11] = static_cast<std::uint8_t>(m_height >> 24);

    f = fopen(file_name, "wb");
    if (f == nullptr)
    {
        delete[] img;
        img = nullptr;

        return;
    }

    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);

    for (std::uint32_t i = 0; i < m_height; i++)
    {
        fwrite(img + (m_width * (m_height - i - 1) * 3), 3, m_width, f);
        fwrite(bmppad, 1, (4 - (m_width * 3) % 4) % 4, f);
    }

    fclose(f);
    f = nullptr;

    delete[] img;
    img = nullptr;
}
