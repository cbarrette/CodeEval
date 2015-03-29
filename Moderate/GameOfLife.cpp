#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	getline(file,line);
	file.seekg(0, ios::beg);
	int width=line.length();
	bool universe[102][102][11]={0}; //Actual game grid is 100*100, the one used is surrounded by dead cells to reduce checks
	//TODO change logic so it uses a temp array instead of just writing to next in line
	int y=1;
	while(getline(file,line)){
		for(int x=1;x<width+1;x++){
			if(line.substr(x-1,1)=="*"){
				universe[x][y][0]=true;
			}
		}
		y++;
	}
	for(int i=0;i<10;i++){	//Main loop
		for(int y=1;y<width+1;y++){
			for(int x=1;x<width+1;x++){
				int neighbors=0;
				
				neighbors+=(universe[x-1][y-1][i])?1:0;
				neighbors+=(universe[x][y-1][i])?1:0;
				neighbors+=(universe[x+1][y-1][i])?1:0;
				neighbors+=(universe[x+1][y][i])?1:0;
				neighbors+=(universe[x-1][y][i])?1:0;
				neighbors+=(universe[x+1][y+1][i])?1:0;
				neighbors+=(universe[x][y+1][i])?1:0;
				neighbors+=(universe[x-1][y+1][i])?1:0;

				if(universe[x][y][i]){
					if(neighbors<2||neighbors>3){
						universe[x][y][i+1]=false;
					}else{
						universe[x][y][i+1]=true;
					}
				}else if(!universe[x][y][i]){
					if(neighbors==3){
						universe[x][y][i+1]=true;
					}
				}
			}
		}
	}
	for(int y=1;y<width+1;y++){
		for(int x=1;x<width+1;x++){
			if(universe[x][y][10]){
				cout<<'*';
			}else{
				cout<<'.';
			}
		}
		cout<<endl;
	}
	return 0;
}


/*
    Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by overcrowding.
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
*/
