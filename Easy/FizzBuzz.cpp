#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char *argv[]){
	int data[3];
	ifstream f;
	f.open(argv[1]);
	while(f>>data[0]>>data[1]>>data[2]){
		for(int x=1;x<=data[2];x++){
			if(x%data[0]!=0&&x%data[1]!=0){
				cout<<x;
			}
			if(x%data[0]==0){
				cout<<"F";
			}
			if(x%data[1]==0){
				cout<<"B";
			}
			cout<<" ";
		}
		cout<<endl;
	}


	return 0;
}
