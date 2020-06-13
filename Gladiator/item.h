#include<string>

class item{
public:
    std::string name;
    int attackvalue;
    int defencevalue;
    bool heal;

    item();
    item(std::string name, int attack, int defence, bool h);
};