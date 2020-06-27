#include<string>
using namespace std;

class Unit
{
    public:
        int health;
        int skill;
        int attackbonus;
        int defencebonus;
        string name;
        bool alive;

        Unit();
        Unit(int h, int s, int a, int d);
        void changename(string n);
        virtual void print();
        virtual bool attack(Unit& target);
        void damage(int amount);

        virtual int attack_strength() { return skill + attackbonus; };
        virtual int defence_strength() { return skill + defencebonus; };

        int attack_roll();
        int defence_roll();
};
