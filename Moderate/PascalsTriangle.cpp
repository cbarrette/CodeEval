#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	int x;
	vector<vector<int> > triangle;
	vector<int>tmp;
	tmp.push_back(0);
	tmp.push_back(1);
	tmp.push_back(0);
	triangle.push_back(tmp);
	while(file>>x){
		while(x>triangle.size()){
			tmp.clear();
			tmp.push_back(0);
			for(int i=1;i<triangle[triangle.size()-1].size();i++){
				tmp.push_back((triangle[triangle.size()-1][i-1]+triangle[triangle.size()-1][i]));
			}
			tmp.push_back(0);
			triangle.push_back(tmp);
		}
		for(int i=0;i<x;i++){
			for(int ii=1;ii<triangle[i].size()-1;ii++){
				cout<<triangle[i][ii]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
/*
 A Pascals triangle row is constructed by looking at the previous row and adding the numbers to its left and right to arrive at the new value. If either the number to its left/right is not present, substitute a zero in it's place. More details can be found here: Pascal's triangle. E.g. a Pascal's triangle upto a depth of 6 can be shown as:

            1
          1   1
        1   2   1
       1  3   3   1
     1  4   6   4   1
    1  5  10  10  5   1

Input sample:

Your program should accept as its first argument a path to a filename. Each line in this file contains a positive integer which indicates the depth of the triangle (1 based). E.g.

6

Output sample:

Print out the resulting pascal triangle upto the requested depth in row major form. E.g.

1 1 1 1 2 1 1 3 3 1 1 4 6 4 1 1 5 10 10 5 1
*/
