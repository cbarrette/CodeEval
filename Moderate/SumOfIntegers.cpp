#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	
	while(getline(file,line)){
		if(line!=""){
			int list[100]={};
			int index=0;
			int pos;
			stringstream ss(line);
			while(ss>>list[index]){
				pos=ss.tellg();
				ss.seekg(pos+1);
				if(!(ss.peek()<=0||ss.peek()>=0)){
					ss.seekg(pos+2);
				}
				index++;
			}
			int largest=-1234567;
			for(int step=0;step<=index;step++){
				int current=0;
				for(int start=0;start<index-step;start++){
					current=0;
					for(int x=start;x<index-step;x++){
						current+=list[x];
					}
					if(current>largest){
						largest=current;
					}
				}
			}
			cout<<largest<<endl;
		}
	}
	return 0;
}
