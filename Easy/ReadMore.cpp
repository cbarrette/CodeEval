#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char const* argv[]){
	const int lineLength=55;
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		if(line!=""){
			if(line.length()>lineLength){
				line=line.substr(0,40);
				string safe=line;
				if(line.substr(line.length()-1,line.length())==" "){
					line=line.substr(0,line.length()-1);
				}else{
					while(line.length()&&line.substr(line.length()-1,line.length())!=" "){
						line=line.substr(0,line.length()-1);
					}
					if(line.length()==0){
						line=safe;
					}
					if(line.substr(line.length()-1,line.length())==" "){
						line=line.substr(0,line.length()-1);
					}
				}
				line+="... <Read More>";
			}
			cout<<line<<endl;
		}
	}
	return 0;
}
