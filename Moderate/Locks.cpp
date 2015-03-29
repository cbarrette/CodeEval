#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		if(line!=""){
			int amountUnlocked=0;
			stringstream stream(line);
			int doorsNum, iters;
			stream>>doorsNum;
			iters=stream.tellg();
			stream.seekg(iters+1);
			stream>>iters;
			bool doors[doorsNum];
			for(int i=0;i<doorsNum;i++){
				doors[i]=true;
			}
			for(int i=0;i<iters-1;i++){
				for(int x=1;x<doorsNum;x+=2){
					doors[x]=false;
				}
				for(int x=2;x<doorsNum;x+=3){
					doors[x]=!doors[x];
				}
			}
			doors[doorsNum-1]=!doors[doorsNum-1];
			for(int i=0;i<doorsNum;i++){
				if(doors[i]){
					amountUnlocked++;
				}
			}
		cout<<amountUnlocked<<endl;
		}
	}
	return 0;
}
