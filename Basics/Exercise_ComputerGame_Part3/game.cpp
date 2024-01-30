#include <iostream>
#include <cstdint>

#include "game.h"

void game(void)
{
    uint32_t player_position = START;
    char next_move = 'x';
    bool check = false;

    std::cout << "Welcome to our little game. In order to win, you have to reach the endline. Have fun!!"
       << std::endl;

    /*The do-while loop is perfect for the case when we expect at least one input,
    but we don't know how much there will be in the end. This loop should repeat itself aslong the
    check is false, that means the input is not 'a' or 'd'*/
    do
    {
        for(uint32_t i = 0u; i < LEN_X; ++i)
        {
            if(i == player_position)
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

        if(player_position == GOAL)
        {
            std::cout << "Congratulation! You have won!!" << std::endl;
            break;
        }

        std::cout << "Where do you want to go next? (a - left or d - right): ";
        std::cin >> next_move;

        check = ((next_move == LEFT) || (next_move == RIGHT)); //The bool value is "true" if the input is either 'a' or 'd'

        if(check)
        {
            if(next_move == 'a')
            {
                if(player_position == START)
                {
                    std::cout << "You are already at the beginning!" << std::endl;
                    continue;
                }
                std::cout << "The player moverd to the left!" << std::endl;
                player_position--;
            }
            else
            {
                std::cout << "The player moved to the right!" << std::endl;
                player_position++;
            }
        }
        else
        {
            std::cout << "The input is invalid. Try again!" << std::endl;
        }

    } while (true);

}
