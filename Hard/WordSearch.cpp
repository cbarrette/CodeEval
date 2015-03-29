#include <iostream>
#include <fstream>

using namespace std;

bool pathFinder(char copy[][6], int x, int y, string line, int linePos);

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	char board[5][6]={{'*','*','*','*','*','*'},
										{'*','A','B','C','E','*'},
										{'*','S','F','C','S','*'},
										{'*','A','D','E','E','*'},
										{'*','*','*','*','*','*'}};
	while(file>>line){
		if(line!=""){
			int x,y;
			x=y=1;
			bool found=false;
			while(y<5&&found==false){
				found=pathFinder(board,x,y,line,0);
				x++;
				if(x==6){
					y++;
					x=0;
				}
			}
			if(found){
				cout<<"True\n";
			}else{
				cout<<"False\n";
			}
		}
	}
	return 0;
}

bool pathFinder(char board[][6], int x, int y, string line, int linePos){
	if(board[y][x]==line[linePos]){
		char copy[5][6];
		for(int posY=0;posY<5;posY++){
			for(int posX=0;posX<6;posX++){
				copy[posY][posX]=board[posY][posX];	
			}
		}
		copy[y][x]='*';
		linePos++;
		if(	pathFinder(copy,	x,		y+1,	line,	linePos)||
				pathFinder(copy,	x,		y-1,	line,	linePos)||
				pathFinder(copy,	x+1,	y,		line,	linePos)||
				pathFinder(copy,	x-1,	y,		line,	linePos)||linePos==line.length()){
					return true;
				}else{
					return false;
				}
	}else{
		return false;
	}
}
