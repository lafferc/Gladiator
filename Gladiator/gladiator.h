#ifndef __GLADIATOR_H__
#define __GLADIATOR_H__

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
            Elite, // elite gladiators
        };

        static const int MAX_HEALTH = 100;
        static const int MAX_STRONG_ATT = 10;


        Gladiator();
        Gladiator(std::string name, int health, int skill, int abonus, int dbonus, int money, Rank rank);
        static Gladiator* factory(Rank rank);
        static Unit* create_condemned();

        void print();

        /// <summary>
        /// Adds h health up to <c>MAX_HEALTH<c>
        /// also adds the same radio of s_a_remaining up to MAX_STRONG_ATT
        /// </summary>
        /// <param name="h"></param>
        void heal(int h);

        bool attack(Unit& target);
        bool strongattack(Unit& target);

        /// <summary>
        /// Takes money from target
        /// </summary>
        /// <param name="target"></param>
        /// <returns>amount taken</returns>
        int loot(Gladiator& target);

    private:
        Rank rank;
        int kills;
        int healitems;
        int money;
        int s_a_remaining;

        void on_kill();
};

static std::ostream& operator<<(std::ostream& os, Gladiator::Rank& rank)
{
    switch (rank)
    {
    case Gladiator::Rank::Condemnabitur:
        os << "condemnabitur";
        break;
    case Gladiator::Rank::Crupellarii:
        os << "crupellarii";
        break;
    case Gladiator::Rank::Rudiarius:
        os << "rudiarius";
        break;
    case Gladiator::Rank::Elite:
        os << "elite gladiator";
        break;
    }
    return os;
}

#endif // !__GLADIATOR_H__