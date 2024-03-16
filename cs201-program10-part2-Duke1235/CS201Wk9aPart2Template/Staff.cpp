#include "Staff.h"
//initalize the staff class
Staff::Staff() : Person() {
    type = ' ';
    hours = 0;
    hrlyRate = 0.0;
    totalStaff++;
}
//set the uniqe values for the staff class
Staff::Staff(char t, string l, string f, int a, int h, float hr) : Person(l, f, a) {
    type = t;
    hours = h;
    hrlyRate = hr;
    totalStaff++;
}

//set the print fucntion for the staff class
void Staff::print() {
    cout << type << left << setw(4) << " "
        << setw(15) << lname
        << setw(15) << fname
        << setw(5) << right << age << "      "
        << setw(6) << left << " HRLY: " << hrlyRate << endl;
}
static int totalStaff;