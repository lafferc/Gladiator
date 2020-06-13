#include <iostream>
#include "unit.h"
#include <string>
using namespace std;


unit::unit()
{
    name = "unit";
    health = (rand()%100 + 1);
    skill = (rand()%5 + 1);
    attackbonus = (rand()%5 + 1);
    defencebonus = (rand()%5 + 1);
    alive = true;
}

unit::unit(int h, int s, int a, int d)
{
    health = h;
    skill = s;
    attackbonus = a;
    defencebonus = d;
    alive = true;
}

void unit::changename(string n)
{	
    name = n;
}

void unit::print()
{
    cout << name << endl;
    cout << "Health=" << health << endl;
    cout << "Skill=" << skill << endl;
    cout << "attack strength=" << (skill + attackbonus) << endl;
    cout << "defense strength=" << (skill + defencebonus) << endl;

    if(alive == true)
        cout << "alive \n";
    else
        cout << "dead \n";
    cout << endl;
}

bool unit::attack(unit& target)
{
    int attackvalue, defensevalue, roll, damage;
    
    roll = (rand()%6 + 1);
    attackvalue = (skill + attackbonus) * roll;
 
    roll = (rand()%6 + 1);
    defensevalue = (target.skill + target.defencebonus) * roll;
    
    damage = attackvalue - defensevalue;
    
    if(damage > 0)
    {
        target.health = target.health-damage;
        if(target.health < 0)
        {
            target.health = 0;
            target.alive = false;
        }
        return true;
    }
    else
    {
        cout << name << "'s attack failed\n";
        return false;
    }
}
