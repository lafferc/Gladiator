#include <iostream>
#include <string>

#include "levels.h"
using namespace std;

void battle(Gladiator& player, Unit& oponent)
{
    oponent.print();

    while (player.is_alive() && oponent.is_alive())
    {
        char command;
        bool success;

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
    const int num_opponents = 5;

    cout << "You must defeat the " << num_opponents << " others that have also been condemned\n";
    cout << "Your stats:\n";
    player.print();
    system("Pause");

    for (int i = 0; i < num_opponents; i++)
    {
        Unit* opponent;

        opponent = Gladiator::create_condemned();

        battle(player, *opponent);

        if (player.is_dead())
        {
            cout << "You were killed by " << *opponent << endl;
            cout << "You died in the arena\n";

            delete opponent;
            return false;
        }
        delete opponent;
    }

    cout << "You are alone in the arena, surrounded by your fallen foe\n";
    system("Pause");

    cout << "You barely have time to catch your breath, when a gate opens and another gladiator enters.\nThis is not going to be easy\n";

    player.heal(25);
    player.print();

    system("Pause");

    boss = Gladiator::factory(Gladiator::Rank::Crupellarii);

    battle(player, *boss);

    if (boss->is_dead())
    {
        cout << "\nGood work you kill the gladiator\n";
        cout << "\ngold taken from " << *boss << ": " << player.loot(*boss) << endl;
        player.print();
    }
    else if (player.is_dead()) {
        cout << "You died in the arena\n";
    }

    delete boss;

    return player.is_alive();
}

bool level2(Gladiator& player)
{
    const int num_opponents = 2;

    cout << "You survived your punishment in the arena, but you are not free to go, you will live out your days in servitude.\n";
    cout << "Lucky for you an owner of one of the local ludi(gladiator schools) saw you in the arenaand purchased you before you were sent to the slave market.\n";
    cout << "Why is this lucky, you ask ? As a gladiator you will have the change to buy your freedom, if you survive long enough that is." << endl;
    system("Pause");

    player.set_rank(Gladiator::Rank::Crupellarii);
    cout << "Your stats:\n";
    player.print();

    cout << "You will now fight in the arena once again, this time you will face " << num_opponents << " opponents" << endl;
    system("Pause");

    for (int i = 0; i < num_opponents; i++)
    {
        Gladiator* opponent;

        opponent = Gladiator::factory(Gladiator::Rank::Crupellarii);

        battle(player, *opponent);

        if (opponent->is_dead())
        {
            cout << "Gold taken from " << *opponent << ": " << player.loot(*opponent) << endl;
        }
        else if (player.is_dead())
        {
            cout << "You were killed by " << *opponent << endl;
            cout << "You died in the arena\n";
            delete opponent;
            return false;
        }

        delete opponent;
    }
    return player.is_alive();
}

bool level3(Gladiator& player)
{
    Gladiator* opponent;

    cout << "You have proved your worth in the arena once again. You will now face more experienced members of the ludus." << endl;
    cout << "Your stats:\n";
    player.print();
    system("Pause");

    opponent = Gladiator::factory(Gladiator::Rank::Rudiarius);
    
    battle(player, *opponent);

    if (opponent->is_dead())
    {
        cout << "Gold taken from " << *opponent << ": " << player.loot(*opponent) << endl;
    }
    else if (player.is_dead())
    {
        cout << "You were killed by " << *opponent << endl;
        cout << "You died in the arena\n";
    }

    delete opponent;

    return player.is_alive();
}

bool level4(Gladiator& player)
{
    Gladiator* opponent;

    cout << "Your fights in the arena are starting to draw a crowd, you will now face one of the top gladiators in the ludus." << endl;
    cout << "Your stats:\n";
    player.print();
    system("Pause");

    opponent = Gladiator::factory(Gladiator::Rank::Elite);

    battle(player, *opponent);

    if (opponent->is_dead())
    {
        cout << "Gold taken from " << *opponent << ": " << player.loot(*opponent) << endl;
    }
    else if (player.is_dead())
    {
        cout << "You were killed by " << *opponent << endl;
        cout << "You died in the arena\n";
    }
    delete opponent;

    return player.is_alive();
}

std::vector<level_t> load_levels()
{
    std::vector<level_t> levels;

    levels.push_back(level1);
    levels.push_back(level2);
    levels.push_back(level3);
    levels.push_back(level4);

    return levels;
}