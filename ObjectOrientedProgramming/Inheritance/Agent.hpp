#pragma once

#include <string>
#include <iostream>
#include <cstdint>

//Parent class
class Agent
{
    public: //In Base class and in Derived class and outside of the classes
        Agent(const std::string &name, const std::uint32_t id)
            : m_name(name), m_id(id)
        {
            std::cout << "Agent Constructor!\n";
        }
        ~Agent()
        {
            std::cout << "Agent Destructor!\n";
        }

    //Restricted for when out of scope (like private), BUT not for the children class
    //If we would use private instead, it would be restricted for children class as well
    protected:
        const std::string m_name;
        const std::uint32_t m_id;
};

class Player : public Agent     //Create a class Player which inherits the attributes from parent class
{
    public:
        Player(const std::string &name, const std::uint32_t id)
            : Agent(name, id)
        {
            std::cout << "Player Constructor!\n";
        }
        ~Player()
        {
            std::cout << "Player Destructor!\n";
        }
};

class NPC : public Agent     //Create a class NPC which inherits the attributes from parent class
{
    public:
        NPC(const std::string &name, const std::uint32_t id)
            : Agent(name, id)
        {
            std::cout << "NPC Constructor!\n";
        }
        ~NPC()
        {
            std::cout << "NPC Destructor!\n";
        }
};
