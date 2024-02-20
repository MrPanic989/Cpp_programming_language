#pragma once

#include <cstdint>
#include <vector>

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

std::uint32_t random_uint(const std::uint32_t lower, const std::uint32_t upper);
std::int32_t random_int(const std::int32_t lower, const std::int32_t upper);

Coordinate random_coordinate(const std::uint32_t lower_x, const std::uint32_t upper_x,
                             const std::uint32_t lower_y, const std::uint32_t upper_y);

void move_obstacles(std::vector<Coordinate> &obstacles);

bool is_finished(const Coordinate &player);

void print_game_state(const Coordinate &player, const std::vector<Coordinate> &obstacles);

void execute_move(Coordinate &player, const MovePlayer move, const std::vector<Coordinate> &obstacles);

void game(void);
