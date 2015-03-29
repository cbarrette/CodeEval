#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class Point{
public:
	int x;
	int y;
	Point(int y, int x){this->x=x; this->y=y;}	
	Point(){}
	Point(const Point& point){x=point.x;y=point.y;}
	string toString(){
		stringstream sy,sx;
		sy<<y; sx<<x;
		string y, x;
		sy>>y; sx>>x;
		return (y+" "+x);
	}
	inline bool operator==(const Point point) const{
		return (x==point.x&&y==point.y);
	}
	inline Point operator+(const Point &point) const{
		return Point(y+point.y,x+point.x);
	}
	inline Point operator-(const Point &point) const{
		return Point(y-point.y,x-point.x);
	}
};

const Point directions[4]={Point(0,-1),Point(-1,0),Point(0,1),Point(1,0)};

int width=0;

bool startLabyrinth[101][101]={false};
bool fat[101][101]={false};
bool shortestPath[101][101]={false};
int shortestPathLength=99999;

Point startPos;
Point exitPos;

void findPath(bool[][101], Point, int);
void printSolution();
void betterPath(const bool[][101], int);
void removeDeadEnds(bool[][101]);
void fillDeadEnd(bool[][101], Point);
bool deadEnd(bool[][101], Point);

int main (int argc, const char* argv[]){
	ifstream file(argv[1]);
	string line;
	//Put first line in array
	bool labyrinth[101][101]={false};
	getline(file,line);
	for(int x=0;x<line.length();x++){
		labyrinth[width][x]=line[x]=='*'?false:true;
		startLabyrinth[width][x]=line[x]=='*'?false:true;
	}
	width++;
	//Put all lines in array
	while(getline(file,line)){
		for(int x=0;x<line.length();x++){
			labyrinth[width][x]=line[x]=='*'?false:true;
			startLabyrinth[width][x]=line[x]=='*'?false:true;
		}
		width++;
	}
	//Find startPos
	for(int x=0;x<width;x++){
		if(labyrinth[0][x]){
			startPos=Point(0,x);
			break;
		}
	}
	//Find exitPos
	for(int x=0;x<width;x++){
		if(labyrinth[width-1][x]){
			exitPos=Point(width-1,x);
			break;
		}
	}
	//Trim fat
	removeDeadEnds(labyrinth);
	for(int y=0;y<width;y++){
		for(int x=0;x<width;x++){
			fat[y][x]=labyrinth[y][x];
		}
	}
	labyrinth[startPos.y][startPos.x]=false;
	findPath(labyrinth, startPos+directions[3], 0);
	labyrinth[exitPos.y][exitPos.x]=false;
	//Output solution
	printSolution();
	return 0;
}

void fillDeadEnd(bool labyrinth[][101], Point currentCoord){
	labyrinth[currentCoord.y][currentCoord.x]=false;
	for(int i=0;i<4;i++){
		Point direction=directions[i]+currentCoord;
		if(labyrinth[direction.y][direction.x]&&deadEnd(labyrinth,direction)){
			fillDeadEnd(labyrinth, direction);
			break;
		}
	}
}

void removeDeadEnds(bool labyrinth[][101]){
	for(int y=1;y<width-1;y++){
		for(int x=1;x<width-1;x++){
			if(deadEnd(labyrinth,Point(y,x))){
				fillDeadEnd(labyrinth, Point(y,x));
			}
		}
	}
}

bool deadEnd(bool labyrinth[][101], Point currentCoord){
	int nb_directions=0;
	for(int i=0;i<4;i++){
		Point direction=directions[i]+currentCoord;
		if(labyrinth[direction.y][direction.x])nb_directions++;
	}
	return nb_directions<=1;
}

void findPath(bool labyrinth[][101], Point currentCoord, int steps){
	//If current steps+minimum steps left (straight lines) are longuer than best solution, return
	if(steps>=shortestPathLength) return;
	steps++;
	labyrinth[currentCoord.y][currentCoord.x]=false;	
	//if exitPos and is better path than before, change solution
	if(currentCoord==exitPos){
		if(steps<shortestPathLength) betterPath(labyrinth, steps);
		labyrinth[currentCoord.y][currentCoord.x]=true;
		return;
	}
	//Surrounding paths
	for(int i=0;i<4;i++){
		Point direction=directions[i]+currentCoord;
		if(labyrinth[direction.y][direction.x]){
			findPath(labyrinth, direction, steps);
		}
	}
	labyrinth[currentCoord.y][currentCoord.x]=true;
}

void printSolution(){
	for(int y=0;y<width;y++){
		for(int x=0;x<width;x++){
			cout<<(startLabyrinth[y][x]^shortestPath[y][x]?' ':(startLabyrinth[y][x]?'+':'*'));
		}
		cout<<endl;
	}
}

void betterPath(const bool labyrinth[][101], int steps){
	for(int y=0;y<width;y++){
		for(int x=0;x<width;x++){
			shortestPath[y][x]=(labyrinth[y][x]^fat[y][x]);
			shortestPathLength=steps;
		}
	}
}
