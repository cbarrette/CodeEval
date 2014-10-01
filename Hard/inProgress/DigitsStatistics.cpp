#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <string>
#include <sstream>
#include <stdint.h>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file;
	file.open(argv[1]);
	int occ[10]={};
	string line;
	uint64_t a,n;
	while(getline(file,line)){
		stringstream stream(line);
		stream>>a>>n;
	
	
	
	
	return 0;
}










/*
	ifstream file;
	file.open(argv[1]);
	int occ[10]={};
	string line;
	uint64_t a,n;
	while(getline(file,line)){
		stringstream stream(line);
		stream>>a>>n;
		for(uint64_t i=1;i<=n;i++){
			uint64_t y=pow(a,i);
			y%=10;
			occ[y]++;
		}
		for(int i=0;i<10;i++){
			cout<<i<<": "<<occ[i];
			if(i<9){
				cout<<", ";
			}
		}
		cout<<endl;
	}
	return 0;
}
*/
