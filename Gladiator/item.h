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