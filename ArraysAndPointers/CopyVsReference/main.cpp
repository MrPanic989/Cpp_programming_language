#include <iostream>

//Input only
void f1(int v)      //The entire variable a is COPIED to the variable v. Not optimal
{
    std::cout << "f1: " << v << '\n';
    std::cout << &v << '\n';    //0xcbf0
}

void f2(int* v)     //The address is COPIED from the variable a and called up by the pointer.
{                   //C style, semi-optimal
    std::cout << "f2: " << *v << '\n';
    std::cout << v << '\n';     //0xcc1c
}

//Input - Output. E.g. void f3(const int& v) -> Input only because of const
void f3(int& v)     //The actual variable a is called by REFERENCE.
{                   //C++ style, optimal!!
    std::cout << "f3: " << v << '\n';
    std::cout << &v << '\n';    //0xcc1c
}


int main(void)
{
    int a = 23;
    std::cout << &a << '\n';    //0xcc1c

    f1(a);
    f2(&a);
    f3(a);

    return 0;
}
