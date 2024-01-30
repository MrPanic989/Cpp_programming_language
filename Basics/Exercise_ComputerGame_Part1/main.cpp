/*We will program a small game where the player can move left and right on, first of all, a 1D game board.
Later this will also be a 2D game board with additional obstacles.
Since we haven't gotten that far yet, we'll first take care of the left/right controls.

Exercise 1
Implement the following code:
- The user can enter via terminal whether they want to move to the left ('a') or to the right ('d').
*/
#include <iostream>
#include <cstdint>

int main(void)
{
    char next_move;
    bool check;

    /*The do-while loop is perfect for the case when we expect at least one input,
    but we don't know how much there will be in the end. This loop should repeat itself aslong the
    check is false, that means the input is not 'a' or 'd'*/
    do
    {
        std::cout << "Where do you want to go next? (a - left or d - right): ";
        std::cin >> next_move;

        check = ((next_move == 'a') || (next_move == 'd')); //The bool value is "true" if the input is either 'a' or 'd'

        if(check)
        {
            if(next_move == 'a')
            {
                std::cout << "The player moverd to the left!" << std::endl;
            }
            else
            {
                std::cout << "The player moved to the right!" << std::endl;
            }
        }
        else
        {
            std::cout << "The input is invalid. Try again!" << std::endl;
        }

    } while (!check);   //while check has the value false





    return 0;
}
