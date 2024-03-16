#include "Pet.h"
//initalize the pet 
Pet::Pet() : name("Unknown"), type("Unknown") {}
//set the values
Pet::Pet(string name, string type) : name(name), type(type) {}
//set the print function of the pet class
void Pet::print() {
    cout << setw(10) << left << name << " (" << setw(5) << left << type << ")";
}
