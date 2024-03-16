#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Staff.h"
#include "Teacher.h"
#include "Employee.h"
#include "Pet.h"
using namespace std;
//declare the main functions
int readFile(vector<Person>&, vector<Student>&, vector<Teacher>&,vector<Employee>&, vector<Person*>& all);
void printVector(vector<Person>);
void printVector(vector<Student>);
void printVector(vector<Teacher>);
void printVector(vector<Employee>);
void printVector(vector<Person*>);