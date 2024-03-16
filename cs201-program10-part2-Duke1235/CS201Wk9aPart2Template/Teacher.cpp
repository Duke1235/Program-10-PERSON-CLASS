#include "Teacher.h"
//initalize the teacher class, the subclass of Staff with added subject
Teacher::Teacher() : Staff() {
    type = ' ';
    subject = "";
    TeacherTotal++;
}
//initalize the values
Teacher::Teacher(char t, string l, string f, int a, int h, float hr, string Sub) : Staff(t, l, f, a, h, hr) {
    type = 'T';
    subject = Sub;
    TeacherTotal++;
}

//give the print function of the teacher class
void Teacher::print() {
    cout << setw(5) << left << type << setw(15) << left << lname
        << setw(12) << left << fname << setw(8) << right << age << setw(4) << ""
        << setw(6) << left << "HRLY: " << setw(7) << left << hrlyRate << setw(8) << left << "SUBJECT: " 
        << setw(23) << left << subject << setw(6) << left;
        //if the pets is empty print none
        if (pets.empty()) {
            cout << "NONE";
        }
        //else print the pets in the pet vector
        else {
            for (auto& pet : pets) {
                

                pet.print();
                cout << "  ";
            }
        }
        cout << endl;
}
static int TeacherTotal;