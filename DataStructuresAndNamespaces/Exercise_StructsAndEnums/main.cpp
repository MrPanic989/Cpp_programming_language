/*
- Task 1:
Implements the following structure PlayerData:
    id: uint32_t
    x_pos: float
    y_pos: float
    health: uint32_t
    energy: uint32_t
    team:€[ALLIED,ENEMY]

- Task 2:
Write a function that returns the player's current position.
Initialize two players in the main function with positions of your own design.
*/
#include <iostream>
#include <cstdint>

#include "exercise.hpp"

int main(void)
{
    auto player_1 = PlayerData{
        .id = 1u,
        .x_pos = -2.0f,
        .y_pos = 4.2f,
        .health = 100u,
        .energy = 120u,
        .team = FriendOrFoe::ALLIED};
    auto player_2 = PlayerData{
        .id = 2u,
        .x_pos = -2.9f,
        .y_pos = -1.8f,
        .health = 100u,
        .energy = 150u,
        .team = FriendOrFoe::ENEMY};

    print_player_position(player_1);
    print_player_position(player_2);

    return 0;
}
