#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class definition for Hostel
class Hostel {
public:
    string blockName;
    int roomNumber;
    string acNonAc;
    string vegNonVeg;
};

// Class definition for Student
class Student {
private:
    string regno;
    string name;
    string phno;
    Hostel hostel;
    static int Total_Instances;
public:
    void setStudentDetails(string regno, string name, string phno, Hostel hostel) {
        this->regno = regno;
        this->name = name;
        this->phno = phno;
        this->hostel = hostel;
        Total_Instances++;
    }

    void getStudentDetails() {
        cout << "Reg No: " << regno << endl;
        cout << "Name: " << name << endl;
        cout << "Phone No: " << phno << endl;
        cout << "Block Name: " << hostel.blockName << endl;
        cout << "Room Number: " << hostel.roomNumber << endl;
        cout << "AC/Non-AC: " << hostel.acNonAc << endl;
        cout << "Veg/Non-Veg: " << hostel.vegNonVeg << endl;
    }

    static int getTotalInstances() {
        return Total_Instances;
    }

    // Friend function to find students based on block
    friend void FindStudentsBasedOnBlock(vector<Student> students, string blockName);
};

int Student::Total_Instances = 0;

void FindStudentsBasedOnBlock(vector<Student> students, string blockName) {
    cout << "Students in block " << blockName << ":" << endl;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].hostel.blockName == blockName) {
            students[i].getStudentDetails();
            cout << endl;
        }
    }
}

int main() {
    // Create three student instances
    Hostel hostel1 = {"A", 101, "AC", "Veg"};
    Hostel hostel2 = {"B", 201, "Non-AC", "Non-Veg"};
    Hostel hostel3 = {"C", 301, "AC", "Veg"};

    Student student1, student2, student3;
    student1.setStudentDetails("2021001", "John", "1234567890", hostel1);
    student2.setStudentDetails("2021002", "Mary", "2345678901", hostel2);
    student3.setStudentDetails("2021003", "Bob", "3456789012", hostel3);

    // Print student details
    student1.getStudentDetails();
    cout << endl;
    student2.getStudentDetails();
    cout << endl;
    student3.getStudentDetails();
    cout << endl;

    // Print total number of student instances
    cout << "Total number of students: " << Student::getTotalInstances() << endl;

    // Find students based on block
    vector<Student> students = {student1, student2, student3};
    FindStudentsBasedOnBlock(students, "A");

    return 0;
}
