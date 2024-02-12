/*We now want to add obstacles to our 2D playing field.
If the player steps on such an obstacle, then he has lost the game.
This also means that the while loop can end prematurely.
The obstacles are the “X” on the playing field.

We will now set these constantly in the following positions:

const auto obstacles = std::vector<Coordinate>{
     Coordinate{.x = 1, .y = 1},
     Coordinate{.x = 2, .y = 2},
     Coordinate{.x = 3, .y = 3},
};

Note: Since the number of obstacles is constant you could also use an array instead of a vector.
*/
#include <iostream>

#include "game.hpp"

int main(void)
{
    game();

    return 0;
}
