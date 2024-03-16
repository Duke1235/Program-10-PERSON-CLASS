#pragma once

#include "Person.h"
//declare the staff class, the subset of person class
class Staff : public Person {
protected:
    char type;
    int hours;
    float hrlyRate;

public:
    Staff();

    Staff(char t, string l, string f, int a, int h, float hr);
    //to get and set the values
    int getHours() { return hours; }
    float getHrlyRate() { return hrlyRate; }
    void setHours(int h) { hours = h; }
    void setHrlyRate(float hr) { hrlyRate = hr; }

    virtual void print();

    static int totalStaff;
};