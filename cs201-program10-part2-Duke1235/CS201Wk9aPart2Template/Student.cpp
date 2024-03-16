#include "Student.h"
//set the student subclass of person
Student::Student() : Person() {
    type = ' ';
    gpa = 0.0;
    totalStudents++;
}
//initalize the values
Student::Student(string l, string f, int a, float g)
    : Person(l, f, a) {
    type = 'S';
    gpa = g;
    totalStudents++;
}
//expand the print function of student
void Student::print() {
    cout << setw(5) << left << type << setw(15) << left << lname
        << setw(12) << left << fname << setw(8) << right << age << setw(4) << ""
        << setw(5) << left << "GPA:" << gpa << setw(37) << "" << setw(12) << left;
    //after printing the basic info then test if has pets
    if (pets.empty()) {
        cout << "NONE";
    }
    //if they have pets then iterate thrugh the pets printing each
    else {
        for (auto& pet : pets) {
            //print the pet.print()
            
            pet.print();
            cout << "  ";
        }
    }
    cout << endl;
}