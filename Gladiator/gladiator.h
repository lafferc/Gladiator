#include "unit.h"
#include <string>

class Gladiator: public Unit
{
    public: 
        int kills;
        int healitems;
        int money;
        int s_a_remaining;
        std::string rank;

        Gladiator();
        Gladiator(std::string name, int health, int skill, int abonus, int dbonus, int money, std::string rank);
        static Gladiator* factory(string name);
        static Unit* create_condemned(string name);

        void print();
        void heal(int h);
        bool attack(Unit& target);
        bool strongattack(Unit& target);
        void on_kill();
};
