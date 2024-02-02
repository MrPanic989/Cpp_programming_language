/*We will now split our "game" code into several functions:
- bool is_finished(const std::uint32_t player)
- void print_game_state(const std::uint32_t player)
- void execute_move(std::uint32_t &player, const char move)
- void game()

This means that in our “game” functions will be:
-is_finished
-print_game_state
-execute_move

called.
*/
#include <iostream>

#include "game.hpp"

int main(void)
{
    game();

    return 0;
}
