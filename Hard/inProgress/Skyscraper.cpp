#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		stringstream ss(line);
		bool landscape[102][10002]={false};
		int maxY=0,maxX=0;
		while(!ss.eof()&&!ss.fail()&&ss.peek()!=')'){
			int startX, endX, endY, ssPos;
			ssPos=ss.tellg();
			ss.seekg(ssPos+1);
			ss>>startX;
			ssPos=ss.tellg();
			ss.seekg(ssPos+1);
			ss>>endY;
			ssPos=ss.tellg();
			ss.seekg(ssPos+1);
			ss>>endX;
			ssPos=ss.tellg();
			ss.seekg(ssPos+3);
			if(endY>maxY){
				maxY=endY;
			}
			if(endX>maxX){
				maxX=endX;
			}
				
			}
		}
	}
	//Desired output  1 2 2 4 4 5 5 4 6 0 7 3 11 2 13 7 15 3 17 0

	return 0;
}
