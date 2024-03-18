#include <iostream>
#include <string>
#include <vector>

#include "Agent.hpp"

void printAllAgents(const std::vector<Agent*> &agents)
{       //Takes the vector of Agent pointers and iterates through the list
    for(const auto agent : agents)
    {
        //calls the function in Agent class!! That's why we need the keyword 'virtual'
        agent->print_agent_data();
    }
}

int main(void)
{
    Agent agent1("A1", 0u, 100, 25);
    Player player1("P1", 1, 250, 55);
    NPC npc1("N1", 2, 235, 41);

    //Agent* works due to the fact that every Player object and every NPC object are
    //also a Agent object at the same time (the definition of polymorphism)
    //So, polymorphism works only with pointer
    const auto agents = std::vector<Agent*>{&agent1, &player1, &npc1};
    printAllAgents(agents);

    return 0;
}
