#include <iostream>
#include <cstdint>

#include "exercise.hpp"

void print_player_position(const PlayerData &player)
{
    std::cout << "The coordinates of the player are (" << player.x_pos << ", " <<player.y_pos << ")\n";

}
