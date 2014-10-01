#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		if(line!=""){
			short int arr[20];
			short int arrPos=0;
			stringstream stream(line);
			char foo;
			stream>>arr[arrPos]>>foo;
			arrPos++;
			while(stream>>arr[arrPos]){
				stream>>foo;
				if(arr[arrPos-1]!=arr[arrPos]){
					arrPos++;
				}
			}
			for(int i=0;i<arrPos;i++){
				cout<<arr[i];
				if(i!=arrPos-1){
					cout<<",";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
