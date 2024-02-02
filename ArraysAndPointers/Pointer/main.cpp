#include <iostream>

//Pointer points at a memory address of another variable
//Pointer variables have always memory addresses as values

int main(void)
{
    int number = 23;
    std::cout << "Value of number: " << number << '\n';                             //23
    std::cout << "Address of number: " << &number << '\n';                          //0xc1c

    int* pointer = &number;
    std::cout << "Value of pointer: " << pointer << '\n';                           //0xc1c
    std::cout << "Address of pointer: " << &pointer << '\n';                        //0xc10
    std::cout << "Value of the variable pointer points at: " << *pointer << '\n';   //23

    return 0;
}
