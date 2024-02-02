#include <iostream>
#include <cstdint>

//Keyword 'new' allocates memory on the heap

int main(void)
{   //The variable 'pointer' is on stack and points to a memory address on heap
    //Old approach
    std::int32_t* pointer = new std::int32_t;
    *pointer = 4;

    //Modern approach: allocation and initialization
    auto* pointer2 = new std::int32_t{4};   //One single integer, therefore curly brackets. For array use []

    std::cout << "Address of pointer2: " << &pointer2 << '\n';          //Stack 0x1c1
    std::cout << "Pointer2 points to address: " << pointer2 << '\n';    //Heap 0x00d4
    std::cout << "The value of the address where pointer2 points at: " << *pointer2 << '\n'; // 4

    delete pointer;     //We aren't deleting the pointer variables, but release (free) the
    delete pointer2;    //heap memory again. The pointer points STILL at this memory address, and that
                        //may cause a problem!!!

    std::cout << "Pointer2 points to address: " << pointer2 << '\n';    //Heap 0x00d4
    std::cout << "The value of the address where pointer2 points at: " << *pointer2 << '\n';    //-323883

    pointer = nullptr;  //The pointer points at "nothing"
    pointer2 = nullptr;

    return 0;
}
