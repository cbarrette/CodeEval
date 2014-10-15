#include <iostream>

using namespace std;

int main(){
	int foo = 0x0001;
  char *bar = (char *) &foo;
  cout<<(bar[0]? "LittleEndian" : "BigEndian");
	return 0;
}
