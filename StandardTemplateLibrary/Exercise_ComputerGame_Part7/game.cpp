#include <iostream>
#include <cstdint>
#include <vector>
#include <random>

#include "game.hpp"

/*Using namespace without a name ensures us that the variables in it are
reachable ONLY private in this file!
*/
namespace
{
    constexpr static auto NUM_OBSTACLES = 3u;
    constexpr static auto LEN_X = 5u;
    constexpr static auto LEN_Y = 5u;
    constexpr static auto START = Coordinate{.x = 0, .y = 0};
    constexpr static auto GOAL = Coordinate{.x = LEN_X - 1, .y = LEN_Y - 1};
}; // namespace

std::uint32_t random_uint(const std::uint32_t lower, const std::uint32_t upper)
{
    static auto seed = std::random_device{};   //Attention: some OS doesn't support this
    static auto gen = std::mt19937{seed()};    //Generates a rendom Bit based on the seed
                    //A rendom value from range lower to upper, based on our generator
    static auto dist = std::uniform_int_distribution<std::uint32_t>(lower, upper);
    //static, because we don't have to generate the random values every iteration, but just once
    //and then return one value per iteration

    return dist(gen);
}

std::int32_t random_int(const std::int32_t lower, const std::int32_t upper)
{
    static auto seed = std::random_device{};
    static auto gen = std::mt19937{seed()};
    static auto dist = std::uniform_int_distribution<std::int32_t>(lower, upper);

    return dist(gen);
}

Coordinate random_coordinate(const std::uint32_t lower_x, const std::uint32_t upper_x,
                             const std::uint32_t lower_y, const std::uint32_t upper_y)
{
    return Coordinate{.x = random_uint(lower_x, upper_x), .y = random_uint(lower_y, upper_y)};
}

void move_obstacles(std::vector<Coordinate> &obstacles)
{
    for(auto &obs : obstacles)
    {
        const auto move_x = random_int(-1, 1);
        const auto move_y = random_int(-1, 1);

        const auto move_pos = Coordinate{obs.x + move_x, obs.y + move_y};
        if(move_pos.x >= 0 && move_pos.y >= 0 && move_pos.x < LEN_X && move_pos.y < LEN_Y)
        {
            obs.x += move_x;
            obs.y += move_y;
        }
    }
}

bool is_finished(const Coordinate &player)
{
    if(player.x == GOAL.x && player.y == GOAL.y)
    {
        std::cout << "Congratulation! You have won!!" << std::endl;
        return true;
    }

    return false;
}

void print_game_state(const Coordinate &player, const std::vector<Coordinate> &obstacles)
{
    auto game_state = std::vector<std::string>(LEN_X, std::string(LEN_Y, '.'));
    for(std::size_t i = 0; i < LEN_X; ++i)
    {
        for(std::size_t j = 0; j < LEN_Y; ++j)
        {
            if(i == player.x && j == player.y)
            {
                game_state[i][j] = 'P';
            }
            else if((i == START.x && j == START.y) || (i == GOAL.x && j == GOAL.y))
            {
                game_state[i][j] = '|';
            }
        }
    }
    for(const auto &obs : obstacles)
    {
        game_state[obs.x][obs.y] = 'X';
    }

    for(const auto &row : game_state)
    {
        std::cout << row << '\n';
    }
    std::cout << std::endl;
}

bool has_obstacle(const Coordinate &coord, const std::vector<Coordinate> &obstacles)
{
    for(const auto &obs : obstacles)
    {
        if(coord.x == obs.x && coord.y == obs.y)
        {
            return true;
        }
    }

    return false;
}

void execute_move(Coordinate &player, const MovePlayer move, const std::vector<Coordinate> &obstacles)
{
    /*
    bool check = false;

    check = ((move == MovePlayer::LEFT) || (move == MovePlayer::RIGHT)
            || (move == MovePlayer::UP) || (move == MovePlayer::DOWN));
            //The bool value is "true" if the input is 'a', 'd', 'w' or 's'

    if(check)
    {
        if(move == MovePlayer::LEFT)
        {
            if(player.y == START.y)
            {
                std::cout << "You cannot move to the left!" << std::endl;
            }
            else
            {
                std::cout << "The player moverd to the left!" << std::endl;
                player.y--;
            }
        }
        else if (move == MovePlayer::RIGHT)
        {
            if(player.y == GOAL.y)
            {
                std::cout << "You cannot move to the right!" << std::endl;
            }
            else
            {
                std::cout << "The player moverd to the right!" << std::endl;
                player.y++;
            }
        }
        else if (move == MovePlayer::UP)
        {
            if(player.x == START.x)
            {
                std::cout << "You cannot move up!" << std::endl;
            }
            else
            {
                std::cout << "The player moverd up!" << std::endl;
                player.x--;
            }
        }
        else    //The player moves down
        {
            if(player.x == GOAL.x)
            {
                std::cout << "You cannot move down!" << std::endl;
            }
            else
            {
                std::cout << "The player moverd down!" << std::endl;
                player.x++;
            }
        }
    }
    else
    {
        std::cout << "The input is invalid. Try again!" << std::endl;
    }
    */

    switch(move)
    {
        case MovePlayer::LEFT:
        {                                       //we cannot just give player as attribut
                                                //becaus we have to adapt coordinates according
                                                //to next move
            if((player.y == START.y) || has_obstacle({player.x, player.y - 1u}, obstacles))
            {
                std::cout << "You cannot move to the left!" << std::endl;
            }
            else
            {
                std::cout << "The player moverd to the left!" << std::endl;
                player.y--;
            }
            break;
        }
        case MovePlayer::RIGHT:
        {
            if((player.y == GOAL.y) || has_obstacle({player.x, player.y + 1u}, obstacles))
            {
                std::cout << "You cannot move to the right!" << std::endl;
            }
            else
            {
                std::cout << "The player moverd to the right!" << std::endl;
                player.y++;
            }
            break;
        }
        case MovePlayer::UP:
        {
            if((player.x == START.x) || has_obstacle({player.x - 1u, player.y}, obstacles))
            {
                std::cout << "You cannot move up!" << std::endl;
            }
            else
            {
                std::cout << "The player moverd up!" << std::endl;
                player.x--;
            }
            break;
        }
        case MovePlayer::DOWN:
        {
            if((player.x == GOAL.x) || has_obstacle({player.x + 1u, player.y}, obstacles))
            {
                std::cout << "You cannot move down!" << std::endl;
            }
            else
            {
                std::cout << "The player moverd down!" << std::endl;
                player.x++;
            }
            break;
        }
        case MovePlayer::INVALID:
        default:
        {
            std::cout << "The input is invalid. Try again!" << std::endl;
            break;
        }
    }
}

void game(void)
{
    auto player = START;    //takes over the values/coordinate from START
    auto obstacles = std::vector<Coordinate>(3, Coordinate{});
    for(auto &obs : obstacles)
    {
        obs = random_coordinate(1, LEN_X - 1, 1, LEN_Y - 1);
    }

    auto move = MovePlayer::INVALID;
    auto move_char = 'x';

    std::cout << "Welcome to our little game. In order to win, you have to reach the endline. Have fun!!"
       << std::endl;

    /*The do-while loop is perfect for the case when we expect at least one input,
    but we don't know how much there will be in the end. This loop should repeat itself aslong the
    check is false, that means the input is not 'a' or 'd'*/
    do
    {
        print_game_state(player, obstacles);

        std::cout << "Where do you want to go next? (a - left, w - up, s - down, d - right): ";
        std::cin >> move_char;
        move = static_cast<MovePlayer>(move_char);
        execute_move(player, move, obstacles);
        move_obstacles(obstacles);

    } while (!is_finished(player));

}
