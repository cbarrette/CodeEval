#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main (int argc, char const* argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		string answer;
		int i=1, n, p1, p2;
		char foo;
		stringstream ss(line);
		ss>>n>>foo>>p1>>foo>>p2;
		while(i*2<n){
			i*=2;
		}
		while(i!=0||n!=0){
			if(n-i>=0&&n!=0){
				answer+='1';
				n-=i;
				i/=2;
			}else{
				answer+='0';
				i/=2;
			}
		}
		p1=answer.length()-p1;
		p2=answer.length()-p2;
		cout<<(answer[p1]==answer[p2]?"true":"false")<<endl;
	}	
	return 0;
}
