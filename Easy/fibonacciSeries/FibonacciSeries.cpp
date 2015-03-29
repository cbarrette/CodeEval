#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file;
	file.open(argv[1]);
	int x;
	while(file>>x){
		int a,b,c;
		b=c=0;
		a=1;
		for(int i=0;i<x;i++){
			c=a+b;
			b=a;
			a=c;
		}
		cout<<b<<endl;
	}

	return 0;
}
