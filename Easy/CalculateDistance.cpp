#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		if(line!=""){
			stringstream stream(line);
			double x,y,bar;
			short int pos;
			
			//A not so elegant solution for reading the needed input
			stream.seekg(1);
			stream>>bar;
			x=bar;
			pos=stream.tellg();
			stream.seekg(pos+2);
			stream>>bar;
			y=bar;
			pos=stream.tellg();
			stream.seekg(pos+3);
			stream>>bar;
			x-=bar;
			pos=stream.tellg();
			stream.seekg(pos+2);
			stream>>bar;
			y-=bar;
			
			cout<<(int)sqrt(pow(x,2)+pow(y,2))<<endl;
		}
	}
	return 0;
}
