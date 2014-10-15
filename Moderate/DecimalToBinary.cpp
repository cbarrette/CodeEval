#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	long long int decimal;
	while(file>>decimal){
		long long int n=1;
		vector<bool>binary;
		if(decimal!=0){
			while(n<decimal){
				n*=2;
			}
			while(n>0){
				if(decimal-n>=0){
					decimal-=n;
					binary.push_back(1);
				}else if(binary.size()>0){
					binary.push_back(0);
				}
				n/=2;
			}
			for(int x=0;x<binary.size();x++){
				cout<<binary[x];
			}
			cout<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}
