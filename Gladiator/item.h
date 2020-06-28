#ifndef __ITEM_H__
#define __ITEM_H__

#include<string>

class Item{
    public:
        std::string name;
        int attackvalue;
        int defencevalue;
        bool heal;

        Item();
        Item(std::string name, int attack, int defence, bool h);
};
#endif // !__ITEM_H__