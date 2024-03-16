#pragma once

#include "Staff.h"
//declare the employee class
class Employee : public Staff {
protected:
    char type;
    int vacDays;

public:
    Employee();

    Employee(char t, string l, string f, int a, int h, float hr, int vac);
    int getvacDays() { return vacDays; }
    void setvacDays(int vac) { vacDays = vac; }

    void print();

    static int EmployeeTotal;
};