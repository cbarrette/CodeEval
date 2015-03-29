#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	int m,n;
	while(getline(file,line)){
		if(line!=""){
			stringstream ss(line);
			ss>>n;
			int pos=ss.tellg();
			ss.seekg(pos+1);
			ss>>m;
			bool list[n];
			int alive=n;
			for(int i=0;i<n;i++){
				list[i]=true;
			}
			pos=0;
			while(alive!=0){
				int count=0;
				while(count!=m){
					if(list[pos]){
						count++;
					}
					if(count!=m){
						pos++;
						if(pos==n){
							pos=0;
						}
					}
				}
				list[pos]=false;
				cout<<pos<<" ";
				alive--;
			}
			cout<<endl;
		}
	}
	return 0;
}
