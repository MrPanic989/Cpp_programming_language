#include <iostream>
#include <string>

int main(void)
{
    //std::string   //const char[]
    std::string s = "Hello people!";
    std::cout << s << '\n';

    const auto index = s.find("llo");   //If substring found, find() returns the position
                                // of the substring. If not, it returns the value std::string::npos
                            //which is the biggest value a uint64 (that is std::size_t) can represent
    if(index != std::string::npos)
    {
        std::cout << "Found substring!\n";
    }
    else
    {
        std::cout << "Substring not found!\n";
    }

    std::cout << s.empty() << '\n';
    std::cout << s.length() << '\n';

    return 0;
}
