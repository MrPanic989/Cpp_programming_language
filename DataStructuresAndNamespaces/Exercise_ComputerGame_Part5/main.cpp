/*We will now use a 2D playing field.
For the player, the starting point and the goal, we save this position with the following structure:

    struct Coordinate
    {
        std::uint32_t x;
        std::uint32_t y;
    };

The functions must be adapted accordingly. The playing field expands to a 5x5 field.
The player starts at the top left. The target is at the bottom right.

The execute_move function must then ensure that the player does not run out of the playing field.
So both vertically and horizontally!
*/
#include <iostream>

#include "game.hpp"

int main(void)
{
    game();

    return 0;
}
