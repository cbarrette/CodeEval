#include <iostream>
using namespace std;
int main(){
	int noPrime=1;
	int sumPrime=0;
	int x=1;
	int o=0;
	while(noPrime<=1000){
		o=0;
		for(int y=2;y<=x/2;y++){
			if(x%y==0){
				o++;
				if(o>=1){
					break;
				}
			}
		}
		if(o==0&&x!=1){
			sumPrime+=x;
			noPrime++;
		}
		x++;
	}
	cout<<sumPrime<<endl;
	return 0;
}
