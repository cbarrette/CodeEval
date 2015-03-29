#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		if(line!=""){
			stringstream ss(line);
			vector<string>elems;
			string tmp;
			while(ss>>tmp){
				elems.push_back(tmp);
			}
			int x=stoi((elems[elems.size()-1]));
			if(x<=elems.size()-1)
				cout<<elems[elems.size()-x-1]<<endl;
		}
	}
	return 0;
}
/*
 Write a program to determine the Mth to last element of a list.
Input sample:

The first argument will be a path to a filename containing a series of space delimited characters followed by an integer representing a index into the list (1 based), one per line. E.g.

a b c d 4
e f g h 2

Output sample:

Print to stdout, the Mth element from the end of the list, one per line. If the index is larger than the list size, ignore that input. E.g.

a
g
*/
