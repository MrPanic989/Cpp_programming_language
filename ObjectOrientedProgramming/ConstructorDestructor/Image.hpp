#pragma once

#include <cstdint>

class Image
{
    public:
        //Constructor
        Image(const std::uint32_t width, const std::uint32_t height);

        //Destructor: usually only needed when we have to allocate heap memory
        ~Image();

    private:
        //Class members
        std::uint32_t m_width;
        std::uint32_t m_height;
};
