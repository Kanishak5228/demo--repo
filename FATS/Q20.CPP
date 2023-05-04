#include <iostream>
using namespace std;

// Define the student record structure
struct StudentRecord {
    int regno;
    string name;
    string dept;
    union DateOfBirth {
        int day;
        int month;
        int year;
    } dob;
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    // Create an array of StudentRecord of size n
    StudentRecord students[n];

    // Read the student records from the user
    for(int i = 0; i < n; i++) {
        cout << "Enter the details for student #" << i+1 << endl;
        cout << "Regno: ";
        cin >> students[i].regno;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Department: ";
        cin >> students[i].dept;
        cout << "Date of Birth (day month year): ";
        cin >> students[i].dob.day >> students[i].dob.month >> students[i].dob.year;
    }

    // Print the student records for those born after 1st Jan 2007
    cout << "Student records for those born after 1st Jan 2007:" << endl;
    for(int i = 0; i < n; i++) {
        if(students[i].dob.year > 2007 || (students[i].dob.year == 2007 && students[i].dob.month > 1) || (students[i].dob.year == 2007 && students[i].dob.month == 1 && students[i].dob.day > 1)) {
            cout << "Regno: " << students[i].regno << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Department: " << students[i].dept << endl;
            cout << "Date of Birth: " << students[i].dob.day << "/" << students[i].dob.month << "/" << students[i].dob.year << endl;
        }
    }

    return 0;
}
