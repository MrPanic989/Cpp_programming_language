/*Task 1:
Write a function that clears the memory of the image, i.e. the vector should be emptied.
    -void clear_image();

- Task 2;
Write a function that changes the size of the image, i.e. the height or width of the image is changed.
    -void resize_image(const std::uint32_t new_width, const std::uint32_t new_height);
When a dimension (height or width) of the image becomes larger,
the matrix of the image should be filled with 0.

- Task 3:
Write a function that completely fills the image with a color.
    -void fill_image(const std::uint8_t value);
The fill color is given by the variable value.

- Task 4 (additional task):
Write a function that draws a horizontal or vertical line on the image.
    void draw_line(const std::uint32_t x1, const std::uint32_t y1,
    const std::uint32_t x2, const std::uint32_t y2,
    const std::uint8_t value);
*/
#include <iostream>

#include "Image.hpp"

int main(void)
{
    Image image1(100, 400);
    image1.save_image("image1.bmp");

    std::cout << "Create image with (100, 400)" << '\n';
    std::cout << "Act height: " << image1.get_height() << '\n';
    std::cout << "Act width: " << image1.get_width() << '\n';

    image1.resize_image(500, 300);
    image1.fill_image(125);
    image1.save_image("image2.bmp");

    std::cout << "Resize to (500, 300)" << '\n';
    std::cout << "New height: " << image1.get_height() << '\n';
    std::cout << "New width: " << image1.get_width() << '\n';

    //				 x1   y1  x2  y2  val
    image1.draw_line(0, 150, 200, 150, 255);
    image1.save_image("image3.bmp");

    //				 x1   y1  x2  y2  val
    image1.draw_line(150, 0, 150, 200, 255);
    image1.save_image("image4.bmp");

    return 0;
}
