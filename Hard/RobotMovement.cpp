#include <iostream>

using namespace std;

const int WIDTH=4+2;//Add 2 for the empty border, reduces checks
const int START_X=1;
const int START_Y=1;
const int END_X=4;
const int END_Y=4;

int nb_ways=0;

void checkGrid(bool grid[][WIDTH], int y, int x){
	bool gridCpy[WIDTH][WIDTH]={};
	for(int Y=0;Y<WIDTH-1;Y++){
		for(int X=0;X<WIDTH-1;X++){
			gridCpy[Y][X]=grid[Y][X];
		}
	}
	gridCpy[y][x]=false;
	if(x==END_X&&y==END_Y){
		nb_ways++;
		return;
	}
	if(gridCpy[y][x-1])checkGrid(gridCpy, y, x-1);
	if(gridCpy[y-1][x])checkGrid(gridCpy, y-1, x);
	if(gridCpy[y][x+1])checkGrid(gridCpy, y, x+1);
	if(gridCpy[y+1][x])checkGrid(gridCpy, y+1, x);
}

int main (){
	bool grid[WIDTH][WIDTH]={};
	for(int y=1;y<WIDTH-1;y++){
		for(int x=1;x<WIDTH-1;x++){
			grid[y][x]=true;
		}
	}
	checkGrid(grid, START_Y, START_X);
	cout<<nb_ways;
	return 0;
}
