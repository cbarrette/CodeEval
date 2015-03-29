#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

class Point{
public:
	int x;
	int y;
	Point(){}
};
int calculateDistance(Point p1, Point p2);
void cleanLineAndGetCoords(string line, Point points[2]);
void cleanLine(string line, string coords[2]);
void getCoords(string coords[2], Point points[2]);

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		if(line!=""){
			line=line.substr(1,line.length()-2);
			Point points[2];
			cleanLineAndGetCoords(line, points);
			int dist = calculateDistance(points[0], points[1]);
			cout<<dist<<endl;
		}
	}
	return 0;
}
int calculateDistance(Point p1, Point p2){
	int dX = pow(p1.x - p2.x, 2);
	int dY = pow(p1.y - p2.y, 2);
	double dist = sqrt(dX + dY);
	return (int)dist;
}

void cleanLineAndGetCoords(string line, Point points[2]){
	string coords[2];
	cleanLine(line, coords);
	getCoords(coords, points);
}

void cleanLine(string line, string coords[2]){
	coords[0]=line.substr(0,line.find(")"));
	coords[1]=line.substr(line.find("(")+1, line.length()-1);
}

void getCoords(string coords[2], Point points[2]){
	for(int i=0;i<2;i++){
		char foo;
		stringstream ss(coords[i]);
		ss>>points[i].x;
		ss>>foo;
		ss>>points[i].y;
	}
}


