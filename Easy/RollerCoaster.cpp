#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int main (int argc, char const* argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		if(line=="")continue;
		string result="";
		int letterCaseIndex=0;
		for(int i=0;i<line.length();i++){
			if(isalpha(line[i])){
				result+=(letterCaseIndex%2==0?toupper(line[i]):tolower(line[i]));
				letterCaseIndex++;
			}else{
				result+=line[i];
			}
		}
		cout<<result<<endl;
	}
	return 0;
}
