#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
    auto str = std::string{};
    auto text = std::string{};

    //READ: InputFileStream
    auto input_file = std::ifstream{};
    input_file.open("./TextInput.txt"); //Opens the file
    if(input_file.is_open())    //boolean value true if the file has been opened successful
    {
        while(std::getline(input_file, str))    //gets line per line from input_file and saves it in str
        {
            text += str + '\n';
        }
    }
    input_file.close(); //CLOSE after we get the informations we want!!!

    std::cout << text << '\n';

    const auto search_str = std::string{"eins"};
    const auto replace_str = std::string{"one"};

    const auto idx = text.find(search_str);
    if(idx != std::string::npos)
    {
        text.replace(idx, search_str.size(), replace_str);
    }

    //WRITE:
    auto output_file = std::ofstream{};
    output_file.open("TextOutput.txt");     //If such file exist, it opens it and deletes all the
    if(output_file.is_open())               //information in it
    {
        output_file << text;
    }
    output_file.close();

    return 0;
}
