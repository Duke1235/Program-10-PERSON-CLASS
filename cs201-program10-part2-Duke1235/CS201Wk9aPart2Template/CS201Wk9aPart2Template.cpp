// CS201Wk8PersonClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Function.h"

/*
Name:Alex Ghasemi
Program: PERSON CLASS - 10
Sources: GPT for help with pet class and other
PSUEDO CODE:
Read the file, inputing the data into vectors for each class and then into the all persons class,
catch any data that is not compatable
print the incompatable people
print the classes,
print all of the people while giving a amount of peopel for each
*/

//add Static Member initialization
int Person::totalPeople = 0;
int Student::totalStudents = 0;
int Staff::totalStaff = 0;
int Teacher::TeacherTotal = 0;
int Employee::EmployeeTotal = 0;


int main()
{
    //create a vector of Person type and all other types
    vector<Person> myPeeps;
    vector<Student> myStudents;
    vector<Teacher> myTeacher;
    vector<Employee> myEmployee;
    vector<Person*> allPeople;

    // read the file & load into vector of Personal type
    readFile(myPeeps, myStudents, myTeacher, myEmployee, allPeople);

    cout << "MY PEOPLEssss: " << endl;
    // print the vectors
    printVector(myPeeps);
    printVector(myStudents);
    printVector(myTeacher);
    printVector(myEmployee);
    printVector(allPeople);

}
