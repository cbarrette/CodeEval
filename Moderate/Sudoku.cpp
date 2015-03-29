#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		if(line!=""){
			int n;
			char foo;
			stringstream ss(line);
			ss>>n>>foo;
			int m=(n==4)?10:45;
			int board[n][n];
			for(int y=0;y<n;y++){
				for(int x=0;x<n;x++){
					ss>>board[y][x]>>foo;
				}
			}
			int tmp=0;
			bool isValid=true;
			int x=0,y=0;
			while(isValid&&y<n){
				for(int x=0;x<n;x++){
					tmp+=board[y][x];
				}
				if(tmp!=m){
					isValid=false;
				}
				tmp=0;
				y++;
			}
			tmp=x=y=0;
			while(isValid&&x<n){
				for(int y=0;y<n;y++){
					tmp+=board[y][x];
				}
				if(tmp!=m){
					isValid=false;
				}
				tmp=0;
				x++;
			}
			int row=0,col;
			int max=(n==4)?2:3;
			while(isValid&&row<n){
				col=0;
				while(isValid&&col<n){
					tmp=0;
					for(int y=row;y<max+row;y++){
						for(int x=col;x<max+col;x++){
							tmp+=board[y][x];
						}
					}
					if(tmp!=m){
						isValid=false;
					}
					col+=max;
				}
				row+=max;
			}
			cout<<((isValid)?"True":"False")<<endl;
		}
	}
	return 0;
}
