#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		int count;
		char foo;
		for(int i=0;i<line.length();i++){
			int ii=0;
			count=0;
			while(ii<line.length()){
				if(line[i]==line[ii]){
					count++;
					if(count>1){
						break;
					}
				}
				ii++;
			}
			if(count==1){
				foo=line[i];
				break;
			}
		}
		if(count==1){
			cout<<foo;
		}
		cout<<endl;
	}


	return 0;
}
