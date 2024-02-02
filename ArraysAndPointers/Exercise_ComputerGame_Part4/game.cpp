#include <iostream>
#include <cstdint>

#include "game.hpp"

/*Using namespace without a name ensures us that the variables in it are
reachable ONLY private in this file!
*/
namespace
{
    constexpr static uint32_t LEN_X = 10u;
    constexpr static uint32_t START = 0u;
    constexpr static uint32_t GOAL = 9u;
    constexpr static char LEFT = 'a';
    constexpr static char RIGHT = 'd';
}; // namespace



bool is_finished(const std::uint32_t player)
{
    if(player == GOAL)
    {
        std::cout << "Congratulation! You have won!!" << std::endl;
        return true;
    }

    return false;
}

void print_game_state(const std::uint32_t player)
{
    for(std::size_t i = 0; i < LEN_X; ++i)
    {
        if(i == player)
        {
            std::cout << "P";
        }
        else if(i == START || i == GOAL)
        {
            std::cout << "|";
        }
        else
        {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

void execute_move(std::uint32_t &player, const char move)
{
    bool check = false;

    check = ((move == LEFT) || (move == RIGHT)); //The bool value is "true" if the input is either 'a' or 'd'

    if(check)
    {
        if(move == 'a')
        {
            if(player == START)
            {
                std::cout << "You are already at the beginning!" << std::endl;
            }
            else
            {
                std::cout << "The player moverd to the left!" << std::endl;
                player--;
            }
        }
        else
        {
            std::cout << "The player moved to the right!" << std::endl;
            player++;
        }
    }
    else
    {
        std::cout << "The input is invalid. Try again!" << std::endl;
    }

}

void game(void)
{
    std::uint32_t player = START;
    char move = 'x';

    std::cout << "Welcome to our little game. In order to win, you have to reach the endline. Have fun!!"
       << std::endl;

    /*The do-while loop is perfect for the case when we expect at least one input,
    but we don't know how much there will be in the end. This loop should repeat itself aslong the
    check is false, that means the input is not 'a' or 'd'*/
    do
    {
        print_game_state(player);

        std::cout << "Where do you want to go next? (a - left or d - right): ";
        std::cin >> move;
        execute_move(player, move);

    } while (!is_finished(player));

}
