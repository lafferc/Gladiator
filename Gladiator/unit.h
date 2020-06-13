#include<string>
using namespace std;

class unit{
public:
	int helth, skill, attackbonus, defensebonus;
	string name;
	bool alive;
	int *p;

	unit();
	unit(int h,int s,int a,int d);
	void changename(string n);
	void print();
	bool attack(unit& defender);
};