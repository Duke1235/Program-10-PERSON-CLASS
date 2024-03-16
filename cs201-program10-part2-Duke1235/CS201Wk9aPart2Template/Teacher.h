#pragma once

#include "Staff.h"
//declare the teacher class, a subset of the staff class
class Teacher : public Staff {
protected:
    char type;
    string subject;

public:
    Teacher();

    Teacher(char t, string l, string f, int a, int h, float hr, string sub);
    //to get a give values
    string getsubject() { return subject; }
    void setSubject(string sub) { subject = sub; }

    virtual void print();

    static int TeacherTotal;
};