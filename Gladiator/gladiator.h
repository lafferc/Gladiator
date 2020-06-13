#include "unit.h"
#include <string>

class gladiator
{
    public: 
        unit stats;
        int kills;
        int healitems;
        int money;
        int s_a_remaining;
        std::string rank;

        gladiator();
        gladiator(std::string name, int health, int skill, int abonus, int dbonus, int money, std::string rank);

        void print();
        void heal(int h);
        void normalattack(unit& target);
        void strongattack(unit& target);
};
