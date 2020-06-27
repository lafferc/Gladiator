#include <iostream>
#include <string>
#include <math.h> 

#include "unit.h"
#include "utils.h"
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
    cout << "attack strength: " << attack_strength() << "  defense strength: " << defence_strength() << endl;
    cout << (alive ? "alive" : "dead") << endl;
    cout << endl;
}

bool Unit::attack(Unit& target)
{
    int damage;
    damage = attack_roll() - target.defence_roll();
    
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

int Unit::attack_roll()
{
    return attack_strength() + int(round(((float)attack_strength() * rand_range(1,6))/2));
}

int Unit::defence_roll()
{
    return int(round(((float)defence_strength() * rand_range(1, 6))/2));
}
