#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	int n;
	file>>n;
	string line;
	string lines[n];
	for(int i=0;i<n;i++){
		lines[i]="";
	}
	int curLines=0;
	while(getline(file,line)){
		if(line!=""){
			while(line[line.length()-1]==' '){
				line=line.substr(0,line.length()-2);
			}
			int lLen=line.length();
			for(int i=0;i<n;i++){
				if(lLen>lines[i].length()){
					for(int ii=n-1;ii>i;ii--){
						lines[ii]=lines[ii-1];
					}
					lines[i]=line;
					break;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<lines[i]<<endl;
	}
	return 0;
}
