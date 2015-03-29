#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
using namespace std;


int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	bool pangram;
	char alphabet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	bool isValid;
	while(getline(file,line)){
		for(int i=0;i<line.length();i++){
			line[i]=tolower(line[i]);
		}
		bool pangram=true;
		for(int i=0;i<26;i++){
			if(line.find(alphabet[i])==string::npos){
				pangram=false;
				cout<<alphabet[i];
			}
		}
		if(pangram){
			cout<<"NULL";
		}
		cout<<endl;
	}
	return 0;
}
