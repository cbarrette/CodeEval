#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Group;
class Person;

class Group{
private:
	string name;
	vector<Person*>members;
public:
	Group(string name){
		this->name=name;
	}
	string getName(){
		return name;
	}
	
};

class Person{
private:
	string name;
	vector<Person*>friends;
	vector<Group*>groups;
public:
	Person(string name){
		this->name=name;
	}
	void addFriend(Person &psn){
		friends.push_back(&psn);
	}
	void addGroups(Group &group){
		groups.push_back(&group);
	}
	string getName(){
		return name;
	}
	
};

int main(int argc, char *argv[]){
	ifstream file(argv[1]);
	string line;
	vector<Person*>users;
	vector<Group*>groups;
	while(getline(file,line)){
		string name=line.substr(0,line.find(":"));
		line=line.substr(line.find(":")+1);
		string friends=line.substr(0,line.find(":"));
		string groups=line.substr(line.find(":")+1);
		int i=0;
		while(i<users.size()&&name!=users[i].getName()){
			i++;
		}
		if(i==users.size()){
			cout<<name<<endl;
			users.push_back(new Person(name));
		}
		
	}
	return 0;
}


