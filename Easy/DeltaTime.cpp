#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

int timeToSec(int[]);

int main (int argc, char const* argv[]){
	ifstream file(argv[1]);
	string line;
	while(getline(file,line)){
		if(line!=""){
			stringstream ss(line);
			int timeTmp[3];
			int timeSec[2];
			char foo;
			for(int x=0;x<2;x++){
				for(int i=0;i<3;i++){
					ss>>timeTmp[i];
					if(i<2)ss>>foo;
				}
				timeSec[x]=timeToSec(timeTmp);
			}
		  int diff=(timeSec[0]>timeSec[1])?timeSec[0]-timeSec[1]:timeSec[1]-timeSec[0];
		  for(int i=2;i>0;i--){
			  timeTmp[i]=diff%60;
			  diff-=timeTmp[i];
			  diff/=60;
		  }
		  timeTmp[0]=diff;
		  for(int i=0;i<3;i++){
				cout<<setfill('0')<<setw(2)<<timeTmp[i];
				if(i<2)cout<<":";
			}
			cout<<endl;
		}
	}	
	return 0;
}

int timeToSec(int time[]){
	time[1]+=time[0]*60;
	time[2]+=time[1]*60;
	return time[2];
}
