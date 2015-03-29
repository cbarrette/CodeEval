#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main (int argc, char const* argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		if(line=="")continue;
		stringstream ss1(line.substr(0,line.find("|")));
		stringstream ss2(line.substr(line.find("|")+1));
		vector<int>v1;
		vector<int>v2;
		int foo;
		while(ss1>>foo){
			v1.push_back(foo);
		}
		while(ss2>>foo){
			v2.push_back(foo);
		}
		for(int i=0;i<v1.size();i++){
			cout<<v1[i]*v2[i];
			if(i<v1.size()-1)cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
