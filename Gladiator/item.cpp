#include<string>
#include"item.h"
using namespace std;

item::item(){
	name="";
	attackvalue=0;
	defensevalue=0;
	heal=false;
}
item::item(string n,int a, int d,bool h){
	name=n;
	attackvalue=a;
	defensevalue=d;
	heal=h;
}