#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main (int argc, char const* argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		if(line!=""){
			//Split the line into element specific segments
			float circleX, circleY, circleR, pointX, pointY;
			string circleCenter=line.substr(line.find("(")+1,(line.find(")")-line.find("(")-1));
			line=line.substr(line.find(";")+10);
			string circleRadius=line.substr(0,line.find((";")));
			line=line.substr(line.find(";")+10);
			line=line.substr(0,line.length()-1);
			
			//Convert to floats 
			circleX=atof((circleCenter.substr(0,circleCenter.find(","))).c_str());
			circleY=atof((circleCenter.substr(circleCenter.find(",")+1)).c_str());
			circleR=atof(circleRadius.c_str());
			
			pointX=atof(line.substr(0,line.find(",")).c_str());
			pointY=atof(line.substr(line.find(",")+1).c_str());
			
			//Trig
			float cSqr,dx,dy;
			dx=circleX-pointX;
			dy=circleY-pointY;
			cSqr=circleR*circleR;
			
			cout<<((cSqr>((dx*dx)+(dy*dy)))?"true":"false")<<endl;
		}
	}
	return 0;
}
