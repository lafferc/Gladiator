#include<iostream>
#include"gladiator.h"
#include<string>
using namespace std;

Gladiator::Gladiator()
{
    healitems = 0;
    s_a_remaining = 10;
    kills = 0;
    money = 0;
    rank = "";
}

Gladiator::Gladiator(string n, int health, int skill, int abonus, int dbonus, int m, string r)
    :Unit(health, skill, abonus, dbonus)
{
    name = n;
    healitems = 0;
    kills = 0;
    money = m;
    rank = r;
    s_a_remaining = 10;
}

Gladiator* Gladiator::factory(string name)
{
    Gladiator* g = new Gladiator();

    g->name = name;
    g->health = (rand() % 61 + 40);
    g->skill = (rand() % 12 + 3);
    g->attackbonus = (rand() % 5 + 5);
    g->defencebonus = (rand() % 7 + 3);

    g->kills = ((rand() % 10 + 1) * g->skill);

    if(g->skill < 3)
    {
        g->rank = "condemned";
        g->money = ((rand()%10+1)*(1 + g->kills));
    }
    else if(g->skill < 7)
    {
        g->rank = "slave";
        g->money = ((rand()%30 + 5)*(1 + g->kills));
    }
    else if(g->skill < 12)
    {
        g->rank = "free man";
        g->money = ((rand()%70 + 20)*(1 + g->kills));
    }
    else
    {
        g->rank = "elite gladiator";
        g->money = ((rand()%100 + 50)*(1 + g->kills));
    }

    return g;
}

Unit* Gladiator::create_condemned(string name)
{
    Unit* condemned = new Unit();

    condemned->name = name;
    condemned->health = (rand() % 91 + 10);
    condemned->skill = (rand() % 2 + 1);
    condemned->attackbonus = (rand() % 4);
    condemned->defencebonus = (rand() % 4);

    return condemned;
}

void Gladiator::print()
{
    cout << rank << ": " << name << endl;
    cout << "Health: " << health << "  Skill: " << skill <<endl;
    cout << "attack strength: " << attack_strength() <<"  defense strength: " << defence_strength() << endl;
    cout << "strong attacks remaining: " << s_a_remaining << endl;
    cout << "kills: " << kills << endl;
    cout << "gold coins: " << money << endl;
    if(alive == true)
        cout << "alive \n";
    else
        cout << "dead \n";
    cout << endl;
}

void Gladiator::heal(int h)
{
    health += h;
    if(health > 100)
        health = 100;
}

bool Gladiator::attack(Unit& target)
{
    if (Unit::attack(target))
    {
        if (target.alive == false)
            on_kill();
        return true;
    }
    return false;
}

bool Gladiator::strongattack(Unit& target)
{
    int roll, damage;

    if (s_a_remaining <= 0)
        return false;

    --s_a_remaining;
    
    roll = (rand()%6 + 1);
    damage = attack_strength() * roll;

    target.damage(damage);
    
    if (target.alive == false)
        on_kill();

    return true;
}

void Gladiator::on_kill()
{
    ++kills;
    if (rand() % (100 - (5 * skill)) >= 50)
        ++attackbonus;
    if (rand() % (100 - (5 * skill)) >= 50)
        ++defencebonus;
    ++skill;
}
