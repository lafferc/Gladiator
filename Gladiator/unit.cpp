#include<iostream>
#include"unit.h"
#include<string>
using namespace std;


unit::unit(){
	name="unit";
	helth=(rand()%100+1);
	skill=(rand()%5+1);
	attackbonus=(rand()%5+1);
	defensebonus=(rand()%5+1);
	alive=true;
}

unit::unit(int h,int s,int a,int d){
	helth=h;
	skill=s;
	attackbonus=a;
	defensebonus=d;
	alive=true;
}

void unit::changename(string n){	
	name=n;
}

void unit::print(){
	cout<<name<<endl;
	cout<<"Helth="<<helth<<endl;
	cout<<"Skill="<<skill<<endl;
	cout<<"attack stregth="<<(skill+attackbonus)<<endl;
	cout<<"defense stregth="<<(skill+defensebonus)<<endl;

	if(alive==true)
		cout<<"alive \n";
	else
		cout<<"dead \n";
	cout<<endl;
}

bool unit::attack(unit& defender){
	int attackvalue, defensevalue, roll, damage;
	
	roll=(rand()%6+1);
	attackvalue=(skill+attackbonus)*roll;
 
	roll=(rand()%6+1);
	defensevalue=(defender.skill+defender.defensebonus)*roll;
	
	damage=attackvalue-defensevalue;
	
	if(damage>0){
		defender.helth=defender.helth-damage;
		if(defender.helth<0){
			defender.helth=0;
			defender.alive=false;
		}
		return true;
	}
	else{
		cout<<name<<"'s attack failed\n";
		return false;
	}

	
	
	
}