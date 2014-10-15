#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		if(line!=""){
			vector<int>values;
			stringstream ss(line);
			int x,noAbs;
			ss>>noAbs;
			if(noAbs>1){
				noAbs--;
				bool absDiff[noAbs];
				for(int i=0;i<noAbs;i++){
					absDiff[i]=0;
				}
				while(ss>>x){
					values.push_back(x);
				}
				for(int i=0;i<values.size()-1;i++){
					int tmp=values[i]-values[i+1];
					tmp*=(tmp<0)?-1:1;
					if(tmp<0||tmp>noAbs){
						break;
					}
						absDiff[tmp-1]=true;
				}
				noAbs--;
				while(noAbs>=0&&absDiff[noAbs]){
					noAbs--;
				}
				cout<<((noAbs>=0)?"Not jolly":"Jolly")<<endl;
			}else if(noAbs==1){
				cout<<"Jolly\n";
			}else{
				cout<<"NULL\n";
			}
		}
	}	
	return 0;
}
