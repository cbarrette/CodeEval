#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file;
	file.open(argv[1]);
	int x;
	int sum;
	while(file>>x){
		sum=0;
		while(x!=0){
			sum+=x%10;
			x/=10;
		}
		cout<<sum<<endl;
	}
	return 0;
}
