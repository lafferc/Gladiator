#include<iostream>
#include"gladiator.h"
#include<string>
#include<ctime>
#include<Windows.h>
using namespace std;

void level1(gladiator& player);

void main()
{
    srand((unsigned)time(0));

    string name = "";
    gladiator player;

    SetConsoleTitle(L"Gladiator v0.0.1");

    cout << "What is your name ?...";
    cin >> name;
    cout << "Welcome to Rome " << name << ", you have been condemned to die in the arena\n";
    cout << "Here are your stats\n";

    player = gladiator(name, 100, 1, 1, 1, 0, "condemned");
    player.print();

    cout << "If your health reaches 0 you will die\n starting level 1\n";
    system("Pause");

    level1(player);

    system("Pause");
}

void level1(gladiator& player) {
    gladiator boss;
    unit units[5];
    bool success;
    char command;

    units[0].changename("unit1");
    units[1].changename("unit2");
    units[2].changename("unit3");
    units[3].changename("unit4");
    units[4].changename("unit5");
    boss.stats.changename("gladiator1");

    for (int i = 0; i < 5; i++)
    {
        if (player.stats.alive == false)
        {
            cout << "You were killed by unit" << i << endl;
            break;
        }
        else
            units[i].print();

        while (player.stats.alive == true && units[i].alive == true)
        {
            cout << "use 'a' for normal attack or 's' for strong attack (ignores targets defence rolls). ";
            cin >> command;
            if (command == 's')
            {
                if (player.s_a_remaining != 0)
                {
                    player.strongattack(units[i]);
                    success = true;
                    player.s_a_remaining--;
                }
                else
                {
                    cout << "You cannot perform that attack\n";
                    success = false;
                }
            }
            else
            {
                success = player.stats.attack(units[i]);
            }

            if (success == true)
            {
                units[i].print();
            }
            if (units[i].alive == true)
            {
                success = units[i].attack(player.stats);
                if (success == true)
                {
                    player.stats.print();
                }
            }
        }
        if (player.stats.alive == true)
        {
            player.stats.skill++;
            player.print();
        }
    }

    boss.print();
    while(player.stats.alive==true && boss.stats.alive==true){
        cout<<"use 'a' for normal attack or 's' for strong attack  ";
        cin>>command;
        if(command=='s'){
            if(player.s_a_remaining!=0){
            player.strongattack(boss.stats);
            success=true;
            player.s_a_remaining--;
            }
            else{
                cout<<"You cannot perform that attack\n";
                success=false;
            }
        }
        else
            success = player.stats.attack(boss.stats);

        if(success==true){
            boss.stats.print();
        }
        
        if(boss.stats.alive==true){
            success = boss.stats.attack(player.stats);
            if(success==true){
                player.stats.print();
            }
        }
    }
    if(boss.stats.alive==false){
        cout<<"\nGood work you kill the gladiator\n";
        cout<<"\ngold taken from "<<boss.stats.name<<": "<<boss.money<<endl;
        player.money=player.money+boss.money;
        player.stats.skill=player.stats.skill+2;
        player.print();
    }
    else if(player.stats.alive==false){
        cout<<"You died in the arena\n";
    }

}
