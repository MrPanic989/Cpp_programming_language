#include <iostream>
#include <cstdint>

#include "game.hpp"

/*Using namespace without a name ensures us that the variables in it are
reachable ONLY private in this file!
*/
namespace
{
    constexpr static auto LEN_X = 5u;
    constexpr static auto LEN_Y = 5u;
    constexpr static auto START = Coordinate{.x = 0, .y = 0};
    constexpr static auto GOAL = Coordinate{.x = LEN_X - 1, .y = LEN_Y - 1};
}; // namespace



bool is_finished(const Coordinate &player)
{
    if(player.x == GOAL.x && player.y == GOAL.y)
    {
        std::cout << "Congratulation! You have won!!" << std::endl;
        return true;
    }

    return false;
}

void print_game_state(const Coordinate &player)
{
    for(std::size_t i = 0; i < LEN_X; ++i)
    {
        for(std::size_t j = 0; j < LEN_Y; ++j)
        {
            if(i == player.x && j == player.y)
            {
                std::cout << "P";
            }
            else if((i == START.x && j == START.y) || (i == GOAL.x && j == GOAL.y))
            {
                std::cout << "|";
            }
            else
            {
                std::cout << ".";
            }
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}

void execute_move(Coordinate &player, const MovePlayer move)
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
            break;
        }
        case MovePlayer::RIGHT:
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
            break;
        }
        case MovePlayer::UP:
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
            break;
        }
        case MovePlayer::DOWN:
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
    auto move = MovePlayer::INVALID;
    auto move_char = 'x';

    std::cout << "Welcome to our little game. In order to win, you have to reach the endline. Have fun!!"
       << std::endl;

    /*The do-while loop is perfect for the case when we expect at least one input,
    but we don't know how much there will be in the end. This loop should repeat itself aslong the
    check is false, that means the input is not 'a' or 'd'*/
    do
    {
        print_game_state(player);

        std::cout << "Where do you want to go next? (a - left, w - up, s - down, d - right): ";
        std::cin >> move_char;
        move = static_cast<MovePlayer>(move_char);
        execute_move(player, move);

    } while (!is_finished(player));

}
