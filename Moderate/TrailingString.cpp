#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line, trail;
	while(getline(file,line)){
		if(line!=""){
			int pos=line.find(","); 
			trail=line.substr(pos+1,line.length());
			line=line.substr(0,pos);
			pos=line.length();
			if(pos<trail.length()){
				cout<<0<<endl;
			}else{
				cout<<(trail==line.substr(pos-trail.length(),pos))<<endl;
			}
		}
	}
	return 0;
}
