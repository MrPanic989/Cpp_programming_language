#include <iostream>

unsigned int faculty(unsigned int n);

int main(void)
{
    unsigned int n = 5;
    unsigned int product = faculty(n);

    std::cout << "The product of the faculty function is: " << product << "!" << std::endl;

    return 0;
}

unsigned int faculty(unsigned int n)
{
    if(n == 1)
    {
        return n;
    }

    return n * faculty(n - 1);
}
