#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line,sentence,toRemove;
	while(getline(file,line)){
		if(line!=""){
			sentence=toRemove="";
			int commaIndex=0;
			int i=0;
			while(commaIndex==0){
				if(line[i]==','){
					commaIndex=i;
				}
				i++;
			}
			sentence=line.substr(0,commaIndex);
			toRemove=line.substr(commaIndex+2, line.length());
			for(int i=0;i<toRemove.length();i++){
				sentence.erase(remove(sentence.begin(),sentence.end(),toRemove[i]),sentence.end());
			}
			while(sentence[0]==' '){
				sentence=sentence.substr(1,sentence.length());
			}
			if(sentence.length()>2){
				while(sentence[sentence.length()-1]==' '){
					sentence=sentence.substr(0,sentence.length()-1);
				}
				for(int i=0;i<sentence.length()-1;i++){
					if(sentence[i]==' '&&sentence[i+1]==' '){
						sentence=sentence.substr(0,i)+sentence.substr(i+1,sentence.length());
					}
				}
			}
			cout<<sentence<<endl;
		}
	}
	return 0;
}
