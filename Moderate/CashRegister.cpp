#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	int billValues[12]={10000,5000,2000,1000,500,200,100,50,25,10,5,1};
	string billNames[12]={"ONE HUNDRED", "FIFTY", "TWENTY", "TEN", "FIVE", "TWO", "ONE", "HALF DOLLAR", "QUARTER", "DIME", "NICKEL", "PENNY"};
	while(getline(file,line)){
		stringstream stream(line);
		double PP,CH;
		char foo;	//discarded char
		if(line!=""){
			line="";
			stream>>PP>>foo>>CH;
			if(PP==CH){
				line+="ZERO";
			}else if(PP>CH){
				line+="ERROR";
			}else{
				int change=(CH*100-PP*100);
				short int arrPos=0;
				while(change>0){
					if(change-billValues[arrPos]>=0){
						line+=billNames[arrPos];
						change-=billValues[arrPos];
						if(change!=0){
							line+=",";
						}
					}else{
						arrPos++;
					}
				}
			}
			cout<<line<<endl;
		}
	}
	return 0;
}




