#pragma once
#include <cstdint>
#include <vector>

using GrayscaleMatrix = std::vector<std::vector<std::uint8_t>>;

class Image
{
    public:
        //Constructor
        Image(const std::uint32_t width, const std::uint32_t height);
        //Destructor: usually only needed when we have to allocate heap memory
        ~Image();

        void save_image(const char* file_name) const; //keyword const when the method does read-only computation

    private:
        //Class members
        std::uint32_t m_width;
        std::uint32_t m_height;
        GrayscaleMatrix m_matrix;
};
