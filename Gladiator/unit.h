#include<string>
#include <iostream>

class Unit
{
    public:
        Unit();
        Unit(int h, int s, int a, int d);
        void changename(std::string n);
        virtual void print();
        virtual bool attack(Unit& target);
        void damage(int amount);

        virtual int attack_strength() { return skill + attackbonus; };
        virtual int defence_strength() { return skill + defencebonus; };
        bool is_alive() { return alive; };

        int attack_roll();
        int defence_roll();

        friend std::ostream& operator<<(std::ostream& os, Unit& unit)
        {
            os << unit.name;
            return os;
        };

    protected:
        int health;
        int skill;
        int attackbonus;
        int defencebonus;
        std::string name;
        bool alive;
};
