#include <algorithm>
#include <string> 
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
    ifstream file(argv[1]);
    string line;
    while (getline(file, line)){
       if (line.length() == 0){
           continue;
        }else{
         transform(line.begin(),line.end(),line.begin(),::tolower);
         cout<<line<<endl;
       }
    }
}
