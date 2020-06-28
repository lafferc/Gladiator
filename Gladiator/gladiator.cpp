#include<iostream>
#include<string>
#include<vector>

#include "gladiator.h"
#include "utils.h"
using namespace std;

vector<const char*> g_gladiator_names = {
    "Atticus",
    "Augustus",
    "Brutus",
    "Cato",
    "Claudius",
    "Cornelius",
    "Darius",
    "Gaius",
    "Hadrian",
    "Julius",
    "Marcus",
    "Maximus",
    "Octavius",
    "Quintus",
    "Spartacus",
    "Tiberius",
};

Gladiator::Gladiator()
{
    healitems = 0;
    s_a_remaining = MAX_STRONG_ATT;
    kills = 0;
    money = 0;
    rank = Rank::Crupellarii;
}

Gladiator::Gladiator(string n, int health, int skill, int abonus, int dbonus, int m, Gladiator::Rank r)
    :Unit(health, skill, abonus, dbonus)
{
    name = n;
    healitems = 0;
    kills = 0;
    money = m;
    rank = r;
    s_a_remaining = MAX_STRONG_ATT;
}

Gladiator* Gladiator::factory(Gladiator::Rank rank)
{
    Gladiator* g = new Gladiator();

    g->name = g_gladiator_names[rand() % g_gladiator_names.size()];
    g->rank = rank;

    switch (rank)
    {
    case Gladiator::Rank::Condemnabitur:
        g->health = rand_range(10, 60);
        g->skill = rand_range(1, 2);
        g->attackbonus = rand_range(0, 4);
        g->defencebonus = rand_range(0, 4);
        break;
    case Gladiator::Rank::Crupellarii:
        g->health = rand_range(40, 80);
        g->skill = rand_range(3, 6);
        g->attackbonus = rand_range(3, 6);
        g->defencebonus = rand_range(2, 5);

        g->kills = rand_range(1, 9) * g->skill;
        g->money = rand_range(5, 34) * (1 + g->kills);
        break;
    case Gladiator::Rank::Rudiarius:
        g->health = rand_range(60, 90);
        g->skill = rand_range(7, 11);
        g->attackbonus = rand_range(5, 8);
        g->defencebonus = rand_range(3, 6);

        g->kills = rand_range(1, 9) * g->skill;
        g->money = rand_range(5, 34) * (1 + g->kills);
        break;
    case Gladiator::Rank::Elite:
        g->health = rand_range(80, 100);
        g->skill = rand_range(12, 14);
        g->attackbonus = rand_range(5, 9);
        g->defencebonus = rand_range(3, 9);

        g->kills = rand_range(1, 9) * g->skill;
        g->money = rand_range(5, 34) * (1 + g->kills);
        break;
    }

    return g;
}

Unit* Gladiator::create_condemned()
{
    return factory(Gladiator::Rank::Condemnabitur);
}

void Gladiator::print()
{
    cout << rank << ": " << name << endl;
    cout << "Health: " << health << "  Skill: " << skill <<endl;
    cout << "Attack strength: " << attack_strength() <<"  Defense strength: " << defence_strength() << endl;
    cout << "Strong attacks remaining: " << s_a_remaining << endl;
    cout << "Kills: " << kills << endl;
    cout << "Gold coins: " << money << endl;
    cout << (alive ? "alive" : "dead") << endl;
    cout << endl;
}

void Gladiator::heal(int h)
{
    health += h;
    if(health > MAX_HEALTH)
        health = MAX_HEALTH;

    s_a_remaining += (h * MAX_STRONG_ATT) / MAX_HEALTH;
    if (s_a_remaining > MAX_STRONG_ATT)
        s_a_remaining = MAX_STRONG_ATT;
}

bool Gladiator::attack(Unit& target)
{
    if (Unit::attack(target))
    {
        if (target.is_dead())
            on_kill();
        return true;
    }
    return false;
}

bool Gladiator::strongattack(Unit& target)
{
    if (s_a_remaining <= 0)
        return false;

    --s_a_remaining;
    target.damage(attack_roll());
    
    if (target.is_dead())
        on_kill();

    return true;
}

void Gladiator::on_kill()
{
    ++kills;
    if (rand() % (100 - (5 * skill)) >= 67)
        ++attackbonus;
    if (rand() % (100 - (5 * skill)) >= 67)
        ++defencebonus;
    ++skill;
}

int Gladiator::loot(Gladiator& target)
{
    int amount = target.money;

    target.money -= amount;
    money += amount;

    return amount;
}

