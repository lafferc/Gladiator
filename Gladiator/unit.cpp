#include <iostream>
#include "unit.h"
#include <string>
using namespace std;


unit::unit()
{
    name = "unit";
    health = (rand()%91 + 10);
    skill = (rand()%2 + 1);
    attackbonus = (rand()%4);
    defencebonus = (rand()%4);
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
        target.damage(damage);
        return true;
    }

    return false;
}

void unit::damage(int amount)
{
    health -= amount;
    if (health <= 0)
    {
        health = 0;
        alive = false;
    }
}
