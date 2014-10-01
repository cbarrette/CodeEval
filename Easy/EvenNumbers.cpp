#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
		int n;
	while(!file.eof()&&file>>n){
		cout<<(n%2==0)<<endl;
	}
	return 0;
}
