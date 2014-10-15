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
			vector<int> values;
			stringstream ss(line);
			int x;
			char foo;
			while(ss>>x){
				ss>>foo;
				values.push_back(x);
			}
			bool isFirst=true;
			for(int i=0;i<values.size()-1;i++){
				for(int ii=i+1;ii<values.size()-1;ii++){
					if(values[i]+values[ii]==values[values.size()-1]){
						cout<<((isFirst)?"":";")<<values[i]<<","<<values[ii];
						isFirst=false;
					}
				}
			}
			cout<<((isFirst)?"NULL":"")<<endl;
		}
	}
	return 0;
}
