#include <iostream>
#include <vector>

struct Data
{
    float x;
    float y;
};

int main(void)
{
    auto vector = std::vector<Data>{{10.0f, 2.0f}, {34.0f, 5.9f}};

    //Version 1
    for(const auto &s : vector)
    {
        std::cout << s.x << " " << s.y << std::endl;
    }

    //Version 2: create alias for the attributes
    for(const auto &[x_, y_] : vector)
    {
        std::cout << x_ << " " << y_ << std::endl;
    }

    return 0;
}
