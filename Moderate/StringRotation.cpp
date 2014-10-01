#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line,trail;
	while(getline(file,line)){
		if(line!=""){
			int pos=line.find(",");
			trail=line.substr(pos+1,line.length());
			line=line.substr(0,pos);
			bool isValid=false;
			if(line.length()==trail.length()){
				for(int i=0;i<line.length();i++){
					trail=trail.substr(1,trail.length()-1)+trail[0];
					if(line==trail){
						isValid=true;
						break;
					}
				}
			}
			string output=(isValid)?"True":"False";
			cout<<output<<endl;
		}
	}
	return 0;
}
