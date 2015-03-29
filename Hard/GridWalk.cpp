#include <iostream>
#include <vector>

using namespace std;

class Point{
public:
	int x;
	int y;
	Point(int y, int x){
		this->x=x;
		this->y=y;
	}	
	inline bool operator==(const Point &point) const{
		return (x==point.x&&y==point.y);
	}
};
bool isAccessible(Point);
bool contains(Point);
void checkPoint(Point);
bool positiveCoord(Point);

bool visitedPoints[300][300]={false};
vector<Point> toCheck;
int axis=0;

int main (){
	toCheck.push_back(Point(0,0));
	visitedPoints[0][0]=true;
	int i=0;
	while(i<toCheck.size()){
		checkPoint(toCheck[i]);
		i++;
	}
	cout<<(toCheck.size()-axis-1)*8+axis*4+1;//-1 +1 for (0,0)
	return 0;
}

void checkPoint(Point point){
	Point points[4]={Point(point.y, point.x-1),Point(point.y+1, point.x),
									 Point(point.y, point.x+1),Point(point.y-1, point.x)};//Left, Top, Right, Down
	for(int i=0;i<4;i++){
		if(positiveCoord(points[i])&&isAccessible(points[i])&&!contains(points[i])){
			toCheck.push_back(points[i]);
			if(points[i].x==points[i].y||points[i].y==0){
				axis++;
			}
		}
	}
}

bool positiveCoord(Point point){
	return(point.x>=0&&point.y>=0&&point.y<=point.x);
}

bool contains(Point point){
	if(!visitedPoints[point.y][point.x]){
		visitedPoints[point.y][point.x]=true;
		return false;
	}
	return true;
}

bool isAccessible(Point point){
	int sum=0, y=point.y, x=point.x;
	while(y!=0){
		sum+=y%10;
		y/=10;
	}
	while(x!=0){
		sum+=x%10;
		x/=10;
	}
	return sum<=19;
}
