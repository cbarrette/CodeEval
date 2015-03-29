#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	int size;
	while(getline(file,line)){
		stringstream stream(line);
		stream>>size;
		int foo=0;
		for(int i=0;i<size-1;i++){
			foo+=i;
		}
		int bar;
		int digits=0;
		char ch;
		bool found=false;
		while(line!=""&&stream>>ch>>bar){
			digits+=bar;
		}
		cout<<digits-foo;
		cout<<endl;
	}
	return 0;
}
