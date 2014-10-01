#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>
using namespace std;
//TODO Rewrite with own stack implementation
int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		stringstream stream(line);
		stack <int> pile;
		int foo;
		while(stream>>foo){
			pile.push(foo);
		}
		while(!pile.empty()){
			cout<<pile.top()<<" ";
			pile.pop();
			if(!pile.empty())pile.pop();
		}
		cout<<endl;
	}
	return 0;
}
