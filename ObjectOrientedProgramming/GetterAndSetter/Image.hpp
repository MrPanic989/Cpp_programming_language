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

        //Getter
        std::uint32_t get_width() const;    //read-only: private values cannot be manipulated from outside
        std::uint32_t get_height() const;
        GrayscaleMatrix get_matrix() const;
        //Setter: always void as return type
        void set_pixel(const std::uint32_t x, const std::uint32_t y, const std::uint8_t value);

    private:
        //Class members
        std::uint32_t m_width;
        std::uint32_t m_height;
        GrayscaleMatrix m_matrix;
};
