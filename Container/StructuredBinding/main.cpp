#include <iostream>
#include <tuple>
#include <string>

void get_data_old(int &a, std::string &b, double &c)
{
    a = 1223;
    b = "data";
    c = 32352.3;
}

std::tuple<int, std::string, double> get_data()
{
    return std::make_tuple(14234, "new data", 2343.2);
}


//We want to return several information
int main(void)
{
    //Old C++:
    int a = 0;
    std::string b = "";
    double c = 0.0;

    get_data_old(a, b, c);
    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';

    //Modern C++: with structured binding (with alias)
    const auto [id, name, score] = get_data();
    std::cout << id << '\n';
    std::cout << name << '\n';
    std::cout << score << '\n';

    return 0;
}
