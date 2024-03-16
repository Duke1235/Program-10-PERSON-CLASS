#include "Function.h"

int readFile(vector<Person>& people, vector<Student>& students,
    vector<Teacher>& teacher,vector<Employee>& employee , vector<Person*>& allPeople) {

    //OPEN THE INPUT FILE
    ifstream inFile;
    inFile.open("people.txt");
    if (!inFile.is_open()) {
        cout << "File is not open" << endl;
        return 1;
    }

    //SET TEMPORARY VARIABLES FOR INPUTTING PERSON INFORMATION
    string inRec, tempStr;
    vector <string> row;

    //LOOP THROUGH THE INPUT FILE
    while (getline(inFile, inRec)) {
        //CHANGE THE INPUT RECORD inRec TO BECOME STRING STREAM inSS
        //THIS WILL ALLOW US TO USE THE RECORD inRec AS THOUGH IT IS
        //AN INPUT STREAM (USEFUL WHEN INPUT IS NOT FIXED)
        stringstream inSS(inRec);
        row.clear();
        // loop through string stream, partioning on ','
        // push each string onto the row vector
        while (getline(inSS, tempStr, ',')) {
            row.push_back(tempStr);
        }
        // try to create a person object 
        // calling constructor with lastname row[1], firstname row[2] and age
        // convert the string 'age' to an integer
        try {
            //if the type is S(student)
            if (row[0][0] == 'S') {
                //create the pointer
                Student* tempSP = new Student(row[1], row[2], stoi(row[3]), stof(row[4]));
                for (size_t i = 5; i < row.size(); i += 2) {
                    string petName = row[i];
                    // Check for 'none' or end of pet data
                    if (petName == "none" || i + 1 >= row.size()) break;

                    string petType = row[i + 1];
                    Pet newPet(petName, petType);
                    tempSP->addPet(newPet); // Add pet to the Student
                    }
                //put the non pointer in the regular vector and the pointer in the People vector
                students.push_back(*tempSP);
                allPeople.push_back(tempSP);
            }
            //check if the type is T(teacher)
            else if (row[0][0] == 'T') {
                //create the pointer
                Teacher* tempEP = new Teacher(row[0][0], row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), row[6]);
                for (size_t i = 7; i < row.size(); i += 2) {
                    string petName = row[i];
                    // Check for 'none' or end of pet data
                    if (petName == "none" || i + 1 >= row.size()) break;

                    string petType = row[i + 1];
                    Pet newPet(petName, petType);
                    tempEP->addPet(newPet); // Add pet to the teacher
                }
                //put the non pointer in teacher vector and pointer into all people vector
                teacher.push_back(*tempEP);
                allPeople.push_back(tempEP);
            }
            //if the type is E(Employee)
            else if (row[0][0] == 'E') {
                //initalize the pointer
                Employee* tempEP = new Employee(row[0][0], row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), stoi(row[6]));
                for (size_t i = 7; i < row.size(); i += 2) {
                    string petName = row[i];
                    // Check for 'none' or end of pet data
                    if (petName == "none" || i + 1 >= row.size()) break;

                    string petType = row[i + 1];
                    Pet newPet(petName, petType);
                    tempEP->addPet(newPet); // Add pet to the Employee
                }
                // put the non pointer into employee vector and the pointer into vector
                employee.push_back(*tempEP);
                allPeople.push_back(tempEP);
            }
            else {
                // if valid, push the object onto the vector
                
                Person* tempPP = new Person(row[1], row[2], stoi(row[3]));
                for (size_t i = 4; i < row.size(); i += 2) {
                    string petName = row[i];
                    // Check for 'none' or end of pet data
                    if (petName == "none" || i + 1 >= row.size()) break;

                    string petType = row[i + 1];
                    Pet newPet(petName, petType);
                    tempPP->addPet(newPet); // Add pet to the person
                }
                //put the non pointer into the vector and the pointer in the all people vector
                people.push_back(*tempPP);
                allPeople.push_back(tempPP);
            }
        }
        catch (...) {
            //if it can not read or reads the wrong value then it is caught here
            //create a vector for all the string values separated by a comma
            vector<string> error;
            //make the error line a stream
            stringstream err(inRec);
            //get temp string
            string line;
            //continuesly reads the error line separated by a comma
            while (getline(err, line, ',')) {
                error.push_back(line);
            }
            cout << error[2] << " " << error[1] << " " << "error: INVALID INPUT" << endl;
        }
    }
    inFile.close();
    return 0;
}

// write the code to print the vector
void printVector(vector<Person> people) {

    cout << "\n\n" << setw(5) << left << "TYPE" << setw(15) << left << "LAST NAME"
        << setw(12) << left << "FIRST NAME" << setw(8) << right << "AGE" << setw(4) << ""
        << setw(45) << left << "OTHER INFO" << setw(20) << "PETS" << endl;
    for (int i = 0; i < people.size(); i++)
        people.at(i).print();

    cout << "\nTOTAL PEOPLE: " << (Person::totalPeople - Student::totalStudents - Staff::totalStaff) << endl;
}
//print the vector for students
void printVector(vector<Student> student) {

    cout << "\n\n" << setw(5) << left << "TYPE" << setw(15) << left << "LAST NAME"
        << setw(12) << left << "FIRST NAME" << setw(8) << right << "AGE" << setw(4) << ""
        << setw(45) << left << "OTHER INFO" << setw(20) << "PETS" << endl;
    for (int i = 0; i < student.size(); i++)
        student.at(i).print();

    cout << "\nTOTAL STUDENTS: " << Student::totalStudents << endl;
}

//print the vector for teachers
void printVector(vector<Teacher> teacher) {

    cout << "\n\n" << setw(5) << left << "TYPE" << setw(15) << left << "LAST NAME"
        << setw(12) << left << "FIRST NAME" << setw(8) << right << "AGE" << setw(4) << ""
        << setw(45) << left << "OTHER INFO" << setw(20) << "PETS" << endl;
    for (int i = 0; i < teacher.size(); i++)
        teacher.at(i).print();

    cout << "\nTOTAL STAFF: " << Teacher::TeacherTotal << endl;
}
//print the vectors for employees
void printVector(vector<Employee> employee) {

    cout << "\n\n" << setw(5) << left << "TYPE" << setw(15) << left << "LAST NAME"
        << setw(12) << left << "FIRST NAME" << setw(8) << right << "AGE" << setw(4) << ""
        << setw(45) << left << "OTHER INFO" << setw(20) << "PETS" << endl;
    for (int i = 0; i < employee.size(); i++)
        employee.at(i).print();

    cout << "\nTOTAL STAFF: " << Employee::EmployeeTotal << endl;
}

//print the vector for the pointers of all the people
void printVector(vector<Person*> people) {

    cout << "\n\n" << setw(5) << left << "TYPE" << setw(15) << left << "LAST NAME"
        << setw(12) << left << "FIRST NAME" << setw(8) << right << "AGE" << setw(4) << ""
        << setw(45) << left << "OTHER INFO" << setw(20) << "PETS" << endl;
    for (int i = 0; i < people.size(); i++)
        people.at(i)->print();
    
    cout << setw(15) << left << "\nTOTAL PEOPLE: " << (Person::totalPeople - Student::totalStudents - Staff::totalStaff) << endl;
    cout << setw(15) << left << "TOTAL STUDENTS: " << Student::totalStudents << endl;
    cout << setw(15) << left << "TOTAL TEACHERS: " << Teacher::TeacherTotal << endl;
    cout << setw(15) << left << "TOTAL EMPLOYEES: " << Employee::EmployeeTotal << endl;
    cout << setw(15) << left << "TOTAL PEOPLE IN ALL: " << Person::totalPeople << endl;
}