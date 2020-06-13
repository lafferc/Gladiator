#include<string>
#include"item.h"

item::item()
{
    name = "";
    attackvalue = 0;
    defencevalue = 0;
    heal = false;
}

item::item(std::string n, int a, int d, bool h)
{
    name = n;
    attackvalue = a;
    defencevalue = d;
    heal = h;
}