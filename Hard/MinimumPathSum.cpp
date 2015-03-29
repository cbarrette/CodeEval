#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int n;
int minPath;

const int TMP=10;

void findPath(int array[][TMP], int y, int x, int pathsum){
	int arrayCpy[TMP][TMP];
	for(int posY=0;posY<n;posY++){
		for(int posX=0;posX<n;posX++){
			arrayCpy[posY][posX]=array[posY][posX];
		}
	}
	pathsum+=arrayCpy[y][x];
	if(pathsum>minPath){
	
	return;
	}
	if(y==x&&x==n-1){
		if(pathsum<minPath)minPath=pathsum;
		return;
	}
	if(x<=n-2)findPath(arrayCpy, y, x+1, pathsum);
	if(y<=n-2)findPath(arrayCpy, y+1, x, pathsum);
	return;
}

int main (int argc, char const* argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		stringstream ss(line);
		ss>>n;
		minPath=999999;
		int array[TMP][TMP];
		for(int y=0;y<n;y++){
			getline(file,line);
			stringstream ss(line);
			for(int x=0;x<n;x++){
			char foo; //Discard
			ss>>array[y][x];
			if(x<n-1)ss>>foo;
			}
		}
		findPath(array, 0, 0, 0);
		cout<<minPath<<endl;
	}
	return 0;
}
