#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	vector<vector<int> >triangle;

	while(getline(file,line)){ //Read file into vectors
		if(line!=""){
			stringstream ss(line);
			int x;
			vector<int> tmp;
			while(ss>>x){
				tmp.push_back(x);
			}
			triangle.push_back(tmp);
		}	
	}
	
	//Start from the bottom of the triangle and add the greater of each pair to it's ancestor
	//Thereby bringing the greatest sum to the top
	for(int y=triangle.size()-1;y>0;y--){
		for(int x=0;x<triangle[y].size()-1;x++){
			triangle[y-1][x]+=(triangle[y][x]>triangle[y][x+1])?triangle[y][x]:triangle[y][x+1];
		}
	}
	cout<<triangle[0][0];
	return 0;
}
