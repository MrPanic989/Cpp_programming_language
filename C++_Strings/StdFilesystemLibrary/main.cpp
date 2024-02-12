#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(void)
{
    fs::path workspace_path = "C:/Users/sinis/C++_programming_language";
    fs::path chapter_path;
    chapter_path = workspace_path;
    chapter_path /= "C++_Strings";  //In this case, the /= does not mean "devided by". It is an operator
                                //that implements flash character (for the path), appropriate for your
                                //operating system
    std::cout << workspace_path << '\n';
    std::cout << chapter_path << '\n';

    fs::path current_file_path = fs::current_path();    //fs::current_path() returns automatically
    current_file_path /= "main.cpp";
    std::cout << current_file_path << '\n';         //the folder paht of this file

    std::cout << "relative_path: " << current_file_path.relative_path() << '\n';
    std::cout << "parent_path: " << current_file_path.parent_path() << '\n';
    std::cout << "filename: " << current_file_path.filename() << '\n';
    std::cout << "stem: " << current_file_path.stem() << '\n';
    std::cout << "extension: " << current_file_path.extension() << '\n';

    std::cout << "exists: " << std::boolalpha << fs::exists(current_file_path) << '\n';
    std::cout << "is file: " << std::boolalpha << fs::is_regular_file(current_file_path) << '\n';
    std::cout << "is dir: " << std::boolalpha << fs::is_directory(current_file_path) << '\n';


    fs::path current_path = fs::current_path();           //empty directory_iterator object
    for(auto iter = fs::directory_iterator(current_path); iter != fs::directory_iterator{}; ++iter)
    {
        if(fs::is_regular_file(*iter))
        {
            std::cout << "Is file: " << *iter << '\n';
        }
        else
        {
            std::cout << "Is dir: " << *iter << '\n';
        }
    }

    /*CREATE NEW DIRECTORY:
    fs::path new_directory_path = fs::current_path();
    new_directory_path /= "test";
    if(!fs::exists(new_directory_path))
    {
        fs::create_directory(new_directory_path);
    }

    COPY A FILE:
    fs::path current_file_path_new = fs::current_path();
    current_file_path_new /= "FileSystem2.cpp";

    fs::path new_file_path;
    new_file_path /= new_directory_path;
    new_file_path /= "FileSystemCopy.cc";
    if(!fs::exists(new_file_path))
    {                 which file should be copied
        fs::copy_file(current_file_path, new_file_path);
    }                                       where should the file be copied
    */

    return 0;
}
