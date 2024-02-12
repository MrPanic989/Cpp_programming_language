/*We will use the following type in this exercise:
#include <vector>
#include <cstdint>

using ByteArray = std::vector<std::uint8_t>;

- Task 1:
Writes a function
    std::uint8_t hex_xor(const std::uint8_t hex1, const std::uint8_t hex2);
which accepts two std::uint8_t values and returns the result of the logical XOR operation.

- Task 2:
Writes a function
    ByteArray hex_vector_xor(const ByteArray &vec1, const ByteArray &vec2);
which accepts two ByteArrays and XORed the individual values of the arrays.
The result should be saved in a new vector (ByteArray).
*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "exercise.hpp"

int main()
{
    auto iffile = std::ifstream{};
    iffile.open("text.txt", std::ios::in);

    auto content = std::string{};
    iffile >> content;
    iffile.close();
                            //iterates through text.txt from begin to end and initialize data vector
    auto data = ByteArray(content.begin(), content.end());
    auto key = ByteArray(8, 0xFF);
    const auto cipher_text = hex_vector_xor(data, key);

    for (std::size_t i = 0; i < data.size(); ++i)
    {
        std::cout << "Data[" << i << "] = " << static_cast<int>(data[i])
                  << '\n';
    }
    std::cout << '\n';

    for (std::size_t i = 0; i < cipher_text.size(); ++i)
    {
        std::cout << "Cipher[" << i
                  << "] = " << static_cast<int>(cipher_text[i]) << '\n';
    }
    std::cout << '\n';

    ByteArray message = hex_vector_xor(cipher_text, key);

    for (std::size_t i = 0; i < message.size(); ++i)
    {
        std::cout << "Message[" << i << "] = " << static_cast<char>(message[i])
                  << '\n';
    }
    std::cout << '\n';

    return 0;
}
