#include<iostream>
#include"gladiator.h"
#include<string>
using namespace std;

gladiator::gladiator()
{
    stats = unit((rand()%61 + 40), (rand()%12 + 3), (rand()%5 + 5), (rand()%7 + 3));
    healitems = 0;
    s_a_remaining = 10;
    kills = ((rand()%10 + 1)*stats.skill);
    if(stats.skill < 3)
    {
        rank="condemned";
        money=((rand()%10+1)*(1+kills));
    }
    else if(stats.skill < 7)
    {
        rank = "slave";
        money = ((rand()%30 + 5)*(1 + kills));
    }
    else if(stats.skill < 12)
    {
        rank = "free man";
        money = ((rand()%70 + 20)*(1 + kills));
    }
    else
    {
        rank = "elite gladiator";
        money=((rand()%100 + 50)*(1 + kills));
    }
}

gladiator::gladiator(string name, int health, int skill, int abonus, int dbonus, int m, string r)
{
    stats = unit(health, skill, abonus, dbonus);
    stats.changename(name);
    healitems = 0;
    kills = 0;
    money = m;
    rank = r;
    s_a_remaining = 10;
}

void gladiator::print()
{
    cout << rank << ": " << stats.name << endl;
    cout << "Health: " << stats.health << "  Skill: " << stats.skill <<endl;
    cout << "attack strength: " << (stats.skill+stats.attackbonus) <<"  defense strength: " << (stats.skill+stats.defencebonus) << endl;
    cout << "strong attacks remaining: " << s_a_remaining << endl;
    cout << "kills: " << kills << endl;
    cout << "gold coins: " << money << endl;
    if(stats.alive == true)
        cout << "alive \n";
    else
        cout << "dead \n";
    cout << endl;
}

void gladiator::heal(int h)
{
    stats.health = (stats.health + h);
    if(stats.health > 100)
        stats.health = 100;
}

bool gladiator::normalattack(unit& target)
{
    if (stats.attack(target))
    {
        if (target.alive == false)
            on_kill();
        return true;
    }
    return false;
}

bool gladiator::strongattack(unit& target)
{
    int roll, damage;

    if (s_a_remaining <= 0)
        return false;

    --s_a_remaining;
    
    roll = (rand()%6 + 1);
    damage = (stats.skill + stats.attackbonus) * roll;

    target.damage(damage);
    
    if (target.alive == false)
        on_kill();

    return true;
}

void gladiator::on_kill()
{
    ++kills;
    if (rand() % (100 - (5 * stats.skill)) >= 50)
        ++stats.attackbonus;
    if (rand() % (100 - (5 * stats.skill)) >= 50)
        ++stats.defencebonus;
    ++stats.skill;
}
