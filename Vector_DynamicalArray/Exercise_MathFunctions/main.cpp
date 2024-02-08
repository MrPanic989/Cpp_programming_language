/*
1.) Write a function that fills a vector with increasing values
     void fill_vector(std::vector<double> &vec);
2.)Write a function that outputs the values of a vector
     void print_vector(const std::vector<double> &vec);
3.) Write functions that calculates the -exponential, -natural logarithm values of a
double vector
     void double_vector_exp(std::vector<double> &vec);
Note: Uses std::exp and std::log from <cmath>
[exp(0.0), exp(1.0), ...]
[log(0.0), log(1.0), ...]
4.) Use range-based for loops
*/
#include <iostream>
#include <cmath>
#include <vector>

void fill_vector(std::vector<double> &vec)
{
    for(std::size_t i = 0; auto &value : vec)
    {
        value = static_cast<double>(i);
        ++i;
    }
}

void print_vector(const std::vector<double> &vec)
{
    for(std::size_t i = 0; const auto &value : vec)
    {
        std::cout << "Vector[" << i << "]: " << value << '\n';
    }
    std::cout << '\n';
}

void double_vector_exp(std::vector<double> &vec)
{
    for(auto &value : vec)
    {
        value = std::exp(value);
    }
}

void double_vector_log(std::vector<double> &vec)
{
    for(auto &value : vec)
    {
        value = std::log(value);
    }
}

int main(void)
{
    auto my_vector = std::vector<double>(3, 0.0);

    fill_vector(my_vector);
    print_vector(my_vector);

    double_vector_exp(my_vector);
    print_vector(my_vector);

    double_vector_log(my_vector);
    print_vector(my_vector);

    return 0;
}
