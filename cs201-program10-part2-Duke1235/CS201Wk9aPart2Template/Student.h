#pragma once
#include "Person.h"
//declare the student class, the subclass of person
class Student : public Person {
private:
	float gpa;

public:
	Student();
	Student(string l, string f, int a, float g);
	//to get and give values
	float getGPA() { return gpa; }
	void  setGPA(float g) { gpa = g; }

	void print();
	static int totalStudents;
};