#include "unit.h"
#include <string>

class Gladiator: public Unit
{
    public: 
        enum class Rank
        {
            Condemnabitur, // condemned
            Crupellarii, // trainee gladiators
            Rudiarius, // freeman 
            Elite, //
        };

        int kills;
        int healitems;
        int money;
        int s_a_remaining;


        Gladiator();
        Gladiator(std::string name, int health, int skill, int abonus, int dbonus, int money, Rank rank);
        static Gladiator* factory(Rank rank);
        static Unit* create_condemned();

        void print();
        void heal(int h);
        bool attack(Unit& target);
        bool strongattack(Unit& target);
        void on_kill();
        std::string rank_str();

    private:
        Rank rank;
};
