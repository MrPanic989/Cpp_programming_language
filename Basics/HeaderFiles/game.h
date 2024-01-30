//The "name".h is a file where all the functions of our program are declared
/*#ifndef GAME_H
#define GAME_H      This is how you include the 'Include Guards' in C programming language

void game(void);

#endif
*/

//This is how you include the 'Include Guards' in C++ programming language
#pragma once    //It asks the compiler, if the code of this file is already included in some other
                //and if so, to just ignore this code so it wouldn't copypaste it multiple times, which
                //would result in a compiler error
void game(void);
