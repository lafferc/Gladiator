#include<iostream>
#include"gladiator.h"
#include<string>
#include<ctime>
using namespace std;

void level1(gladiator& A);

void main(){
	srand((unsigned)time(0));
	
	string name="";
	gladiator A;

	cout<<"what is you name ?...";
	cin>>name;
	cout<<"welocme to rome "<<name<<", you have been comdemed to die in the arena\n";
	cout<<"here are your stats\n";

	A=gladiator(name,100,1,0,0, 0,"condemed");
	A.print();

	cout<<"if your helth reaches 0 you will die\n starting level 1\n";
	system("Pause");
	
	level1(A);

	system("Pause");
}



void level1(gladiator& A){
	gladiator B;
	unit units[5];
	bool z;
	char command;

	units[0].changename("unit1");
	units[1].changename("unit2");
	units[2].changename("unit3");
	units[3].changename("unit4");
	units[4].changename("unit5");
	B.stats.changename("gladiator1");

	//*
	for(int i=0;i<5;i++){
		if(A.stats.alive==false){
			cout<<"you were killed by unit"<<i<<endl;
			i=i+10;
		}
		else
		units[i].print();
		while(A.stats.alive==true && units[i].alive==true){
			cout<<"use 'a' for normal attack or 's' for strong attack  ";
			cin>>command;
			if(command=='s'){
				if(A.s_a_remaining!=0){
				A.strongattack(units[i]);
				z=true;
				A.s_a_remaining--;
				}
				else{
					cout<<"you cannot perform that attack\n";
					z=false;
				}
			}
			else{
			z = A.stats.attack(units[i]);
			}

			if(z==true){
				units[i].print();
			}
			if(units[i].alive==true){
				z = units[i].attack(A.stats);
				if(z==true){
					A.stats.print();
				}
			}
		}
		if(A.stats.alive==true){
			A.stats.skill++;
			A.print();
		}
	}//*/
	B.print();
	while(A.stats.alive==true && B.stats.alive==true){
		cout<<"use 'a' for normal attack or 's' for strong attack  ";
		cin>>command;
		if(command=='s'){
			if(A.s_a_remaining!=0){
			A.strongattack(B.stats);
			z=true;
			A.s_a_remaining--;
			}
			else{
				cout<<"you cannot perform that attack\n";
				z=false;
			}
		}
		else
			z = A.stats.attack(B.stats);

		if(z==true){
			B.stats.print();
		}
		
		if(B.stats.alive==true){
			z = B.stats.attack(A.stats);
			if(z==true){
				A.stats.print();
			}
		}
	}
	if(B.stats.alive==false){
		cout<<"\ngood work you kill the gladiator\n";
		cout<<"\ngold taken from "<<B.stats.name<<": "<<B.money<<endl;
		A.money=A.money+B.money;
		A.stats.skill=A.stats.skill+2;
		A.print();
	}
	else if(A.stats.alive==false){
		cout<<"you died in the arena\n";
	}

}