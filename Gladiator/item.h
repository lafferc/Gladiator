#include<string>
using namespace std;

class item{
public:
	string name;
	int attackvalue, defensevalue;
	bool heal;

	item();
	item(string n,int a, int d,bool h);
};