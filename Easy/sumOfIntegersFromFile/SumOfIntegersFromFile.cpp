#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char *argv[]){
	ifstream file;
	file.open(argv[1]);
	int sum=0;
	int x;
	while(file>>x){
		sum+=x;
	}
	cout<<sum;
	return 0;
}
