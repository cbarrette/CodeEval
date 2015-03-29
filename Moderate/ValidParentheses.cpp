#include <iostream>
#include <fstream>

using namespace std;

bool equalQuant(string paren);
bool isInverse(char ch1, char ch2);

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string paren;
	bool isValid;
	int index;
	int openPos;
	while(file>>paren){
	isValid=true;
	index=0;
	if(paren.length()%2!=0){
		isValid=false;
	}else if(!equalQuant(paren)){
		isValid=false;
	}else{
		while(isValid&&index<paren.length()){
			if(isInverse(paren[index],paren[index+1])){
				for(int i=index;i<paren.length()-2;i++){
					paren[i]=paren[i+2];
				}
				index=0;
				paren=paren.substr(0,paren.length()-2);
			}else{
				index++;
			}
		}
		if(paren.length()!=0){
			isValid=false;
		}
	}
		(isValid)?cout<<"True":cout<<"False";
		cout<<endl;
	}
	return 0;
}

bool isInverse(char ch1, char ch2){
	return ((ch1=='('&&ch2==')') || (ch1=='{'&&ch2=='}') || (ch1=='['&&ch2==']'));
}

bool equalQuant(string paren){
	int par=0;
	int brack=0;
	int curly=0;
	for(int i=0;i<paren.length();i++){
		if(paren[i]=='('){
			par++;
		}else if(paren[i]==')'){
			par--;
		}else if(paren[i]=='{'){
			curly++;
		}else if(paren[i]=='}'){
			curly--;
		}else if(paren[i]=='['){
			brack++;
		}else if(paren[i]==']'){
			brack--;
		}
	}
	return (par==0&&brack==0&&curly==0);
}
