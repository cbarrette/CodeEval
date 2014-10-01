#include <iostream>
#include <fstream>
using namespace std;

int main(int arg, char *argv[]){
	int amount,goal;
	ifstream file(argv[1]);
	while(file>>goal){
		amount=0;
		while(goal!=0){
			if(goal-5>=0){
				amount++;
				goal-=5;
			}else if(goal-3>=0){
				amount++;
				goal-=3;
			}else{
				amount++;
				goal-=1;
			}
		}
		cout<<amount<<endl;
	}
	return 0;
}
