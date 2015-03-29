#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	int n;
	while(file>>n){
		int count=0;
		int pow=1;
		while(pow*2<=n){
			pow=pow*2;
		}
		while(n!=0&&pow!=0){
			int m=n-pow;
			if(m>=0&&m%1==0){
				n-=pow;
				count++;
			}
			pow/=2;
		}
		cout<<count<<endl;
	}
	return 0;
}
