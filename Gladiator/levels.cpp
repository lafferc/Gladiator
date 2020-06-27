#include <iostream>
#include <string>

#include "levels.h"
using namespace std;

void battle(Gladiator& player, Unit& oponent)
{
    char command;
    bool success;

    oponent.print();

    while (player.is_alive() && oponent.is_alive())
    {
        cout << "use 'a' for normal attack or 's' for strong attack (ignores targets defence rolls). ";
        cin >> command;
        if (command == 's')
        {
            if ((success = player.strongattack(oponent)) == false)
                cout << "You cannot perform that attack\n";
        }
        else
        {
            if ((success = player.attack(oponent)) == false)
                cout << "Your attack failed\n";
        }

        if (success == true)
        {
            oponent.print();
        }

        if (oponent.is_alive())
        {
            if (oponent.attack(player) == true)
                player.print();
            else
                cout << oponent << "'s attack failed\n";
        }
    }
    if (player.is_alive())
    {
        player.print();
    }
}


bool level1(Gladiator& player) {
    Gladiator* boss;

    cout << "You must defeat the 5 others that have also been condemned\n";

    for (int i = 0; i < 5; i++)
    {
        Unit* unit;

        unit = Gladiator::create_condemned();

        battle(player, *unit);

        if (!player.is_alive())
        {
            cout << "You were killed by " << *unit << endl;
            cout << "You died in the arena\n";
            return false;
        }

        delete unit;
    }

    cout << "You are alone in the arena, surrounded by your fallen foe\n";
    cout << "You barely have time to catch your breath, when a gate opens and another gladiator enters.\n This is not going to be easy\n";

    player.heal(25);
    player.print();

    system("Pause");

    boss = Gladiator::factory(Gladiator::Rank::Crupellarii);

    battle(player, *boss);

    if (boss->is_alive())
    {
        cout << "\nGood work you kill the gladiator\n";
        cout << "\ngold taken from " << boss << ": " << player.loot(*boss) << endl;
        player.print();
    }
    else if (!player.is_alive()) {
        cout << "You died in the arena\n";
    }

    delete boss;

    return player.is_alive();
}


std::vector<level_t> load_levels()
{
    std::vector<level_t> levels;

    levels.push_back(level1);

    return levels;
}