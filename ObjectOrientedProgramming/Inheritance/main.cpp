#include <iostream>

#include "Agent.hpp"

int main(void)
{
    std::cout << "Line 7\n";
    {
        auto agent1 = Agent{"A1", 0u};
    }
    std::cout << "Line 11\n";
    {
        auto player1 = Player{"P1", 1u};    // == Player player1("P1", 1u);
        auto player2 = Player{"P2", 2u};
    }
    std::cout << "Line 16\n";
    {
        auto npc1 = NPC{"N1", 3u};
    }
    std::cout << "Line 20\n";

    return 0;
}
