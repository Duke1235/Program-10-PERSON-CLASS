#include "Employee.h"
//declare the employee standardized values
Employee::Employee() : Staff() {
    type = ' ';
    vacDays = 0;
    EmployeeTotal++;
}
//declare the employee class when called
Employee::Employee(char t, string l, string f, int a, int h, float hr, int vac) : Staff(t, l, f, a, h, hr) {
    type = 'E';
    vacDays = vac;
    EmployeeTotal++;
}

//create a print class
void Employee::print() {
    cout << setw(5) << left << type << setw(15) << left << lname
        << setw(12) << left << fname << setw(8) << right << age << setw(4) << ""
        << setw(6) << left << "HRLY: " << setw(7) << left << hrlyRate 
        << setw(8) << left << "VAC DAYS: " << setw(22) << left << vacDays << setw(12) << left;
    //print the pets that the employee has
    if (pets.empty()) {
        cout << "NONE";
    }
    else {
        for (auto& pet : pets) {
            // print the pet.print()

            pet.print(); 
            cout << "  ";
        }
    }
    cout << endl;
}
static int EmployeeTotal;