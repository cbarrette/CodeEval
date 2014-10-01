#include <iostream>

using namespace std;

bool palindrome(int x);

int main(){
	bool isPrime;
	int prime=0;
	for(int x=1;x<1000;x++){
	isPrime=true;
		for(int y=2;y<x/2;y++){
			if(x%y==0){
				isPrime=false;
			}
		}
		if(isPrime&&palindrome(x)){
			prime=x;
		}
	}
	cout<<prime;
	return 0;
}

bool palindrome(int original){
	int foo=original;
	int bar=0;
	while(foo!=0){
		bar*=10;
		bar+=foo%10;
		foo/=10;
	}
	return original==bar;
}
