#include <iostream>
#include <cstdlib>  //Librari for atoi()

//argc: argument count
//argv: argument values (1 value is always included: the .exe)

int main(int argc, char** argv)
{
    for(int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << '\n';
    }

    if(argc > 1)
    {
        int arg_value = std::atoi(argv[1]);
        std::cout << arg_value << '\n';
    }

    return 0;
}

/*Step 1: start compilation
Step 2: open terminal and move down the folder structure until folder where this main.cpp file is
        cd ArraysAndPointers -> cd CommandlineArgs ->cd buld ->cd Debug
Step 3: type in as many arguments you want: (outDebug.exe always)
        outDebug.exe 23 Manchester -32
*/
