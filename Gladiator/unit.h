#include<string>
using namespace std;

class unit
{
    public:
        int health;
        int skill;
        int attackbonus;
        int defencebonus;
        string name;
        bool alive;

        unit();
        unit(int h, int s, int a, int d);
        void changename(string n);
        void print();
        bool attack(unit& target);
        void damage(int amount);
};
