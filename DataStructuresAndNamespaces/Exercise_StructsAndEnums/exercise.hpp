#pragma once

#include <cstdint>

enum class FriendOrFoe
{
    ALLIED,
    ENEMY,
};

struct PlayerData
{
    std::uint32_t id;
    float x_pos;
    float y_pos;
    std::uint32_t health;
    std::uint32_t energy;
    FriendOrFoe team;
};

void print_player_position(const PlayerData &player);
