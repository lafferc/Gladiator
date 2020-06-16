#include<string>
#include"item.h"

Item::Item()
{
    name = "";
    attackvalue = 0;
    defencevalue = 0;
    heal = false;
}

Item::Item(std::string n, int a, int d, bool h)
{
    name = n;
    attackvalue = a;
    defencevalue = d;
    heal = h;
}