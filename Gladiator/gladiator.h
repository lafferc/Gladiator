#include"unit.h"
#include<string>
using namespace std;

class gladiator{
public: unit stats;
		int kills, healitems, money, s_a_remaining;
		string rank;

		gladiator();
		gladiator(string name,int helth,int skill,int abonus,int dbonus, int money,string rank);

		void print();
		void heal(int h);
		void normalattack(unit& attacked);
		void strongattack(unit& attacked);



};