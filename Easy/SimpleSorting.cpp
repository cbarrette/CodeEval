#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(int argc, char * argv[]){
	ifstream file(argv[1]);
	string line;
	double *numbers=new double[100];
	while(getline(file,line)){
		if(line!=""){	
			stringstream stream(line);
			double input;
			int nIndex=0;
			while(stream>>input){
				numbers[nIndex]=input;
				nIndex++;
			}
			sort(numbers,numbers+nIndex);
			for(int i=0;i<nIndex;i++){
				cout<<fixed<<setprecision(3)<<numbers[i];
				if(i<nIndex-1)cout<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
