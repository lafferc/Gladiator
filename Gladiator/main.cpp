#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>

#include "gladiator.h"
#include "levels.h"
using namespace std;


void main()
{
    srand((unsigned)time(0));

    string name = "";
    Gladiator player;
    int i = 0;

    SetConsoleTitle(L"Gladiator v0.0.3");

    cout << "What is your name ?...";
    cin >> name;
    cout << "Welcome to Rome " << name << ", you have been condemned to die in the arena\n";

    player = Gladiator(name, Gladiator::MAX_HEALTH, 1, 1, 1, 0, Gladiator::Rank::Condemnabitur);

    cout << "If your health reaches 0 you will die\n";

    for (auto& level : load_levels())
    {
        cout << "starting level " << ++i << endl;
        system("Pause");

        if (!level(player))
            break;

        player.heal(Gladiator::MAX_HEALTH);
        system("Pause");
        system("CLS");
    }

    if (player.is_alive())
    {
        cout << "You completed the game" << endl;
    }
    else
    {
        cout << "Game Over!" << endl;
    }
    system("Pause");
}

