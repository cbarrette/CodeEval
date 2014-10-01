#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	for(int y=1;y<=12;y++){
		for(int x=1;x<=12;x++){
			cout<<setw(4)<<x*y;
		}
		cout<<endl;
	}
	return 0;
}
