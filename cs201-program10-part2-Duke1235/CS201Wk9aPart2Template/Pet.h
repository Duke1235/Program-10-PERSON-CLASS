#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//declare the pet class
class Pet {
private:
	string name;
	string type;


public:
	Pet();
	Pet(string name, string type);
	void print();

	//to set and get values
	string getName() { return name; };
	string getType() { return type; };
	void setName(string nam) { name = nam; }
	void setType(string ty) { type = ty; }


};
