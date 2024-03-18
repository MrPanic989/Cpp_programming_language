#pragma once

#include <iostream>
#include <string>
#include <cstdint>

class Agent
{
    public:
        Agent(const std::string &name, const std::uint32_t id,
              const std::uint32_t hp = 0u, const std::uint32_t energy = 0u)
              : m_name(name), m_id(id), m_hp(hp), m_energy(energy)
        {
            std::cout << "Agent Constructor!" << '\n';
        }
        ~Agent()
        {
            std::cout << "Agent Destructor!" << '\n';
        }

        //keyword virtual allows the children class to override this function
        virtual void print_agent_data() const
        {
            std::cout << "Agent hp: " << m_hp << ", energy: " << m_energy << '\n';
        }

    protected:
        const std::string m_name;
        const std::uint32_t m_id;
        std::uint32_t m_hp;
        std::uint32_t m_energy;
};

class Player : public Agent
{
    public:
        Player(const std::string &name, const std::uint32_t id,
               const std::uint32_t hp = 0u, const std::uint32_t energy = 0u)
              : Agent(name, id, hp, energy)
        {
            std::cout << "Player Constructor!" << '\n';
        }
        ~Player()
        {
            std::cout << "Player Destructor!" << '\n';
        }

        //override means that the output should be different than the output from parent print_agent_data
        //function. Otherwise the output of this function would be "Agent hp: " and not "Player hp:"
        void print_agent_data() const override
        {
            std::cout << "Player hp: " << m_hp << ", energy: " << m_energy << '\n';
        }
};

class NPC : public Agent
{
    public:
        NPC(const std::string &name, const std::uint32_t id,
            const std::uint32_t hp = 0u, const std::uint32_t energy = 0u)
            : Agent(name, id, hp, energy)
        {
            std::cout << "NPC Constructor!" << '\n';
        }
        ~NPC()
        {
            std::cout << "NPC Destructor!" << '\n';
        }

        void print_agent_data() const override
        {
            std::cout << "NPC hp: " << m_hp << ", energy: " << m_energy << '\n';
        }
};
