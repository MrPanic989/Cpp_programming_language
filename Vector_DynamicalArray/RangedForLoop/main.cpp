#include <iostream>
#include <vector>

int main(void)
{
    auto vector = std::vector<int>{1, 2, 3, 4, 5};

    //This is the perfect for loop if we want to iterate through the array/vector and
    //and the index is irrelevant
    for(auto value : vector)        //copy of the vector element values
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;


    for(auto &value : vector)   //reference of the element values
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;


    return 0;
}
