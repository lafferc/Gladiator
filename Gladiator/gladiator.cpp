#include<iostream>
#include"gladiator.h"
#include<string>
using namespace std;

gladiator::gladiator(){
	stats= unit((rand()%70+30),(rand()%12+3),(rand()%5+5),(rand()%7+3));
	healitems = 0;
	s_a_remaining= 10;
	kills=((rand()%10+1)*stats.skill);
	if(stats.skill<3){
		rank="condemed";
		money=((rand()%10+1)*(1+kills));
	}
	else if(stats.skill<7){
		rank="slave";
		money=((rand()%30+5)*(1+kills));
	}
	else if(stats.skill<12){
		rank="free man";
		money=((rand()%70+20)*(1+kills));
	}
	else{
		rank="elite gladiator";
		money=((rand()%100+50)*(1+kills));
	}
}

gladiator::gladiator(string name,int helth,int skill,int abonus,int dbonus, int m,string r){
	stats= unit(helth,skill,abonus,dbonus);
	stats.changename(name);
	healitems = 0;
	kills=0;
	money=m;
	rank=r;
	s_a_remaining= 10;
	
}

void gladiator::print(){
	cout<<rank<<": "<<stats.name<<endl;
	cout<<"Helth= "<<stats.helth<<"  Skill= "<<stats.skill<<endl;
	cout<<"attack stregth: "<<(stats.skill+stats.attackbonus)<<"  defense stregth: "<<(stats.skill+stats.defensebonus)<<endl;
	cout<<"strong attacks remaining= "<<s_a_remaining<<endl;
	cout<<"kills= "<<kills<<endl;
	cout<<"gold coins= "<<money<<endl;
	if(stats.alive==true)
		cout<<"alive \n";
	else
		cout<<"dead \n";
	cout<<endl;
	
}

void gladiator::heal(int h){
	stats.helth = (stats.helth+h);
	if(stats.helth<100){
		stats.helth=100;
	}
}

void gladiator::normalattack(unit& attacked){
	bool z=false;
	z=stats.attack(attacked);
	if(z==true){
		if(attacked.alive==false){
			kills++;
			
		}
	}
}

void gladiator::strongattack(unit& attacked){
	int roll, damage;
	
	roll=(rand()%6+1);
	damage=(stats.skill+stats.attackbonus)*roll;

	attacked.helth=(attacked.helth-damage);

	if(attacked.helth<0){
		attacked.helth=0;
		attacked.alive=false;
	}
}