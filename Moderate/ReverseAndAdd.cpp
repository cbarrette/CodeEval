#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;

int64_t reverse(int64_t);
bool isPal(int64_t);

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	int64_t num;
	while(file>>num){
	int n=0;
		while(!isPal(num)){
			n++;
			num+=reverse(num);
		}
		cout<<n<<" "<<num<<endl;
	}
	return 0;
}


int64_t reverse(int64_t num){
	int64_t rev=0;
	while(num!=0){
		rev*=10;
		rev+=(num%10);
		num/=10;
	}
	return rev;
}

bool isPal(int64_t original){
	int64_t foo=original;
	int64_t bar=0;
	while(foo!=0){
		bar*=10;
		bar+=foo%10;
		foo/=10;
	}
	return original==bar;
}
