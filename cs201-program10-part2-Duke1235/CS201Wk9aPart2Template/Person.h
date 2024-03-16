#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include "Pet.h"
using namespace std;
//declare the person class
class Person {
protected:
    char type;
    string lname;
    string fname;
    int age;
    vector<Pet> pets;

public:
    Person();                            //constructor: default
    Person(string l, string f, int a);   //constructor: overloaded (needs correction)

    //add other accessors & mutators
    string getFName() { return fname; }         //accessor (first name)
    string getLName() { return lname; }
    int getAge() { return age; }
    void setFName(string f) { fname = f; }    //mutator (first name)
    void setLName(string l) { lname = l; }
    void setAge(int a) { this->age = a; }
    virtual void print();

    void addPet(Pet& pet) {
        pets.push_back(pet);
    }
    // add static member to count Persons created
    // where would this be updated?
    static int totalPeople;
};