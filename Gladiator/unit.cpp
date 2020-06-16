#include <iostream>
#include "unit.h"
#include <string>
using namespace std;


Unit::Unit()
{
    name = "unit";
    health = 100;
    skill = 1;
    attackbonus = 0;
    defencebonus = 0;
    alive = true;
}

Unit::Unit(int h, int s, int a, int d)
{
    health = h;
    skill = s;
    attackbonus = a;
    defencebonus = d;
    alive = true;
}

void Unit::changename(string n)
{	
    name = n;
}

void Unit::print()
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

bool Unit::attack(Unit& target)
{
    int attackvalue, defensevalue, roll, damage;
    
    roll = (rand()%6 + 1);
    attackvalue = attack_strength() * roll;
 
    roll = (rand()%6 + 1);
    defensevalue = target.defence_strength() * roll;
    
    damage = attackvalue - defensevalue;
    
    if(damage > 0)
    {
        target.damage(damage);
        return true;
    }

    return false;
}

void Unit::damage(int amount)
{
    health -= amount;
    if (health <= 0)
    {
        health = 0;
        alive = false;
    }
}
