/*Implement the following code:
The user can now not only go left or right once, but can also move around the “playing field”
until he reaches the goal.

This is what the terminal output would look like at startup:
P........|

And so after the player moves several times:
|P.......|
The player moved to the right!
|.P......|
The player moved to the right!
|..P.....|
The player moved to the right!
|.P......|
The player moved to the left!

'P' is the player
'|' is the starting point (left) and the destination (right)
'.' are the remaining playing fields
The player wins the game when he enters the rightmost field.
*/
#include <iostream>
#include <cstdint>

int main(void)
{
    uint32_t playing_filed_length = 10u;
    uint32_t start = 0u;
    uint32_t goal = 9u;
    char left = 'a';
    char right = 'd';

    uint32_t player_position = start;
    char next_move = 'x';
    bool check = false;

    std::cout << "Welcome to our little game. In order to win, you have to reach the endline. Have fun!!"
       << std::endl;

    /*The do-while loop is perfect for the case when we expect at least one input,
    but we don't know how much there will be in the end. This loop should repeat itself aslong the
    check is false, that means the input is not 'a' or 'd'*/
    do
    {
        for(uint32_t i = 0u; i < playing_filed_length; ++i)
        {
            if(i == player_position)
            {
                std::cout << "P";
            }
            else if(i == start || i == goal)
            {
                std::cout << "|";
            }
            else
            {
                std::cout << ".";
            }
        }

        std::cout << std::endl;

        if(player_position == goal)
        {
            std::cout << "Congratulation! You have won!!" << std::endl;
            break;
        }

        std::cout << "Where do you want to go next? (a - left or d - right): ";
        std::cin >> next_move;

        check = ((next_move == left) || (next_move == right)); //The bool value is "true" if the input is either 'a' or 'd'

        if(check)
        {
            if(next_move == 'a')
            {
                if(player_position == start)
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

    return 0;
}
