/*The obstacles should now be initialized at random positions.
The obstacles can now also move to a neighboring field.
This always happens when the player has also moved.
This means we now need a random function for the coordinates of the obstacles.
A neighboring field is +1/-1 away from the current position in both vertical and horizontal directions.

Accordingly, there is also a probability that an obstacle will not move each turn.
*/
#include <iostream>

#include "game.hpp"

int main(void)
{
    game();

    return 0;
}
