#include <iostream>
#include <string>
#include <string_view>

//Just a auxiliary function that prints out "allocating" every time a heap memory is reserved,
//that is, every time a string is created
void* operator new(std::size_t count)
{
    std::cout << "allocating" << std::endl;
    return malloc(count);
}

//It takes strings as argument
void do_something1(const std::string &s)
{
    std::cout << s << std::endl;
}

//If we want to read-only a string OR a char[], string_view is the perfect function for it.
//It doesn't create a new string at first, like it is the case with const std::string &s
void do_something2(std::string_view sv) //instead of const std::string ref, just a pointer at the first
{                                       //character plus length
    std::cout << sv << std::endl;
}

int main(void)
{
    auto s = std::string{"Hi, my name is Michael and I am a student."};     //allocating

    auto sub_s = std::string(s.substr(4, 32)); //from where, how many       //allocating
    do_something1(sub_s);

    do_something1("Hi, my name is Michael and I am a student.");            //allocating
    do_something2("Hi, my name is Michael and I am a student.");

    return 0;
}
