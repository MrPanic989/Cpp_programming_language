#pragma once

#include <cstdint>

struct Coordinate
{
    std::uint32_t x;
    std::uint32_t y;
};

enum class MovePlayer
{
    INVALID,
    LEFT = 'a',
    RIGHT = 'd',
    UP = 'w',
    DOWN = 's',
};

bool is_finished(const Coordinate &player);

void print_game_state(const Coordinate &player);

void execute_move(Coordinate &player, const MovePlayer move);

void game(void);
