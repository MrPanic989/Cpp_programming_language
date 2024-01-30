/*Outsource the game logic to its own function in Game.h/.cc.
This “game” function is then called in the main function. For now we will put all the code in a function.
Later we will change this again into several sub-functions.
*/
#include <iostream>
#include <cstdint>

#include "game.h"

int main(void)
{
    game();

    return 0;
}
