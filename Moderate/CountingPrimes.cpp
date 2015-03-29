#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		if(line!=""){
			int n,m;
			stringstream stream(line);
			stream>>n;
			int offset=stream.tellg();
			stream.seekg(offset+1);
			stream>>m;
			int count=0;
			for(int i=n;i<=m;i++){
				bool isPrime=true;
				for(int ii=2;ii<=i/2;ii++){
					if(i%ii==0&&i>3){
						isPrime=false;
						break;
					}
				}
				if(isPrime){
					count++;
				}
			}
			cout<<count<<endl;
		}
	}
	return 0;
}
