#include <iostream>
#include <fstream>
#include <cstdint>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	int64_t primes[1500]={2,3,5}; //stores previously found primes to redue further search times
	int primesPos=2;
	int64_t n;
	int count;
	while(file>>n){
		int i=0;
		i=primes[primesPos];
		while(i<=n){
			i++;
			bool isPrime=true;
			int x=0;
			while(primes[x]<i/2){
				if(i%primes[x]==0){
					isPrime=false;
					break;
				}
				x++;
			}
			if(isPrime){
				primesPos++;
				primes[primesPos]=i;
			}
		}
		i=0;
		while(primes[i]<=n&&i<=primesPos){
			cout<<primes[i];
			i++;
			if(primes[i]<=n&&i<=primesPos){
				cout<<",";
			}
		}
		cout<<endl;
	}
	return 0;
}
