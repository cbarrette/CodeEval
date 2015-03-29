#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <iomanip>

using namespace std;

struct Coord{
	float x;
	float y;
};
double p_distance(Coord, Coord);

int main (int argc, char const* argv[]){
	ifstream file(argv[1]);
	string line;
	
	while(getline(file,line)){
		short int n;
		stringstream ss(line);
		ss>>n;	
		if(n>0){
			Coord points[n];
			for(short int i=0;i<n;i++){
				getline(file,line);
				stringstream ss2(line);
				float x,y;
				ss2>>x>>y;
				points[i].x=x;
				points[i].y=y;
			}
			double shortest=10000;
			for(short int i=0;i<n-1;i++){
				for(short int ii=i+1;ii<n;ii++){
					if(p_distance(points[i],points[ii])<shortest){
						shortest=p_distance(points[i],points[ii]);
					}
				}
			}
			if(shortest<10000){
				cout<<fixed<<setprecision(4)<<shortest<<endl;
			}else{
				cout<<"INFINITY"<<endl;
			}
		}
	}
	return 0;
}

double p_distance(Coord c1, Coord c2){
	float distance, dX, dY;
	dX=pow((c1.x-c2.x),2);
	dY=pow((c1.y-c2.y),2);
	distance=dX+dY;
	return sqrt(distance);
}



