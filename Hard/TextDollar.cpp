#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

string digitText(int);
string numberText(int);
int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	int n;
	while(file>>n){
		string denom;

		//TODO rewrite
		if(n>=100000000){
			cout<<digitText(n/100000000)<<"Hundred";
			denom="Million";
			n%=100000000;
		}
		if(n>=10000000){
			cout<<numberText(n/1000000);
			denom="Million";
			n%=1000000;
		}else if(n>=1000000){
			cout<<digitText(n/1000000);
			denom="Million";
			n%=1000000;
		}
		cout<<denom;
		denom="";
		if(n>=100000){
			cout<<digitText(n/100000)<<"Hundred";
			denom="Thousand";
			n%=100000;
		}
		if(n>=10000){
			cout<<numberText(n/1000);
			denom="Thousand";
			n%=1000;
		}else if(n>=1000){
			cout<<digitText(n/1000);
			denom="Thousand";
			n%=1000;
		}
		cout<<denom;
		if(n>=100){
			cout<<digitText(n/100)<<"Hundred";
			n%=100;
		}
		if(n>=10){
			cout<<numberText(n);
		}else{
			cout<<digitText(n);
		}
		cout<<"Dollars"<<endl;
	}
	return 0;
}
string numberText(int n){
	string text;
	if(n>=10&&n<20){
		switch(n){
			case 10: text="Ten";break;
			case 11: text="Eleven";break;
			case 12: text="Twelve";break;
			case 13: text="Thirteen";break;
			case 14: text="Fourteen";break;
			case 15: text="Fifteen";break;
			case 16: text="Sixteen";break;
			case 17: text="Seventeen";break;
			case 18: text="Eighteen";break;
			case 19: text="Nineteen";break;
		}
	}else{
		switch(n/10){
			case 2: text="Twenty";break;
			case 3: text="Thirty";break;
			case 4: text="Forty";break;
			case 5: text="Fifty";break;
			case 6: text="Sixty";break;
			case 7: text="Seventy";break;
			case 8: text="Eighty";break;
			case 9: text="Ninety";break;
		}
		text+=digitText(n%10);
	}
	return text;
}
string digitText(int n){
	string text;
	switch(n){
		case 1:	text="One";break;
		case 2:	text="Two";break;
		case 3:	text="Three";break;
		case 4:	text="Four";break;
		case 5:	text="Five";break;
		case 6:	text="Six";break;
		case 7:	text="Seven";break;
		case 8:	text="Eight";break;
		case 9:	text="Nine";break;
	}
	return text;
}
