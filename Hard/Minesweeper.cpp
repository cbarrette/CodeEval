#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main (int argc, char const* argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		string dim=line.substr(0,line.find(";"));
		line=line.substr(line.find(";")+1);
		int y,x;
		char foo;
		
		//Get grid size
		stringstream ss(dim);
		ss>>y>>foo>>x;
		//Create and initialize field
		//With a border to reduce checks
		string mineField[y+2][x+2];
		for(int Y=0;Y<y+2;Y+=y+1){
			for(int X=0;X<x+2;X++){
				mineField[Y][X]=".";
			}
		}
		for(int X=0;X<x+2;X+=x+1){
			for(int Y=0;Y<y+2;Y++){
				mineField[Y][X]=".";
			}
		}
		for(int Y=1;Y<y+1;Y++){
			for(int X=1;X<x+1;X++){
				mineField[Y][X]=line[(Y-1)*x+X-1];
			}
		}
		//Go through grid and print mines or nb of adjacent mines
		for(int Y=1;Y<y+1;Y++){
			for(int X=1;X<x+1;X++){
				if(mineField[Y][X]=="*"){
					cout<<mineField[Y][X];
				}else{
					//Ulgy check I know, for loop would be much nicer
					int numMines=0;
					if(mineField[Y-1][X-1]=="*")numMines++;
					if(mineField[Y][X-1]=="*")numMines++;
					if(mineField[Y+1][X-1]=="*")numMines++;
					if(mineField[Y+1][X]=="*")numMines++;
					if(mineField[Y+1][X+1]=="*")numMines++;
					if(mineField[Y][X+1]=="*")numMines++;
					if(mineField[Y-1][X+1]=="*")numMines++;
					if(mineField[Y-1][X]=="*")numMines++;
					cout<<numMines;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
