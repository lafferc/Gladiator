#include<iostream>
#include"gladiator.h"
#include<string>
#include<ctime>
#include<Windows.h>
using namespace std;

void level1(Gladiator& player);

void main()
{
    srand((unsigned)time(0));

    string name = "";
    Gladiator player;

    SetConsoleTitle(L"Gladiator v0.0.2");

    cout << "What is your name ?...";
    cin >> name;
    cout << "Welcome to Rome " << name << ", you have been condemned to die in the arena\n";
    cout << "Here are your stats\n";

    player = Gladiator(name, 100, 1, 1, 1, 0, Gladiator::Rank::Condemnabitur);
    player.print();

    cout << "If your health reaches 0 you will die\n starting level 1\n";
    system("Pause");

    level1(player);

    system("Pause");
}

void battle(Gladiator& player, Unit& oponent)
{
    char command;
    bool success;

    oponent.print();

    while (player.alive == true && oponent.alive == true)
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

        if (oponent.alive == true)
        {
            if (oponent.attack(player) == true)
                player.print();
            else
                cout << oponent.name << "'s attack failed\n";
        }
    }
    if (player.alive == true)
    {
        player.print();
    }
}

void level1(Gladiator& player) {
    Gladiator* boss;

    cout << "You must defeat the 5 others that have also been condemned\n";

    for (int i = 0; i < 5; i++)
    {
        Unit* unit;

        unit = Gladiator::create_condemned();
        
        battle(player, *unit);

        if (player.alive == false)
        {
            cout << "You were killed by " << unit->name << endl;
            cout << "You died in the arena\n";
            return;
        }

        delete unit;
    }

    cout << "You are alone in the arena, surrounded by your fallen foe\n";
    cout << "You barely have time to catch your breath, when a gate opens and another gladiator enters.\n This is not going to be easy\n";

    player.heal(25);
    player.s_a_remaining += 2;
    player.print();

    system("Pause");

    boss = Gladiator::factory(Gladiator::Rank::Crupellarii);

    battle(player, *boss);

    if(boss->alive==false)
    {
        cout << "\nGood work you kill the gladiator\n";
        cout << "\ngold taken from " << boss->name << ": " << boss->money << endl;
        player.money += boss->money;
        player.print();
    }
    else if(player.alive==false){
        cout<<"You died in the arena\n";
    }

    delete boss;
}
