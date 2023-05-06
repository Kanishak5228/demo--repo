 Write a C++ program using classes and objects, which can find out the overall 
average of the entire group ( say n) of patients. A single object with default 
constructor adds 10 patients with 60 kg average weight, while another object of the 
same class with parameterized constructor adds ni patients with wi kg overweight or 
underweight ( for eg., ni=5, and wi=10 means 5 patients are added where their 
average weight is 10 kg above the average weight of 60 kg). ALL objects of this 
patient class (and ONLY objects of this patient class) update the total weight and the 
total number (n) of patients and can display the overall average. Your C++ program 
should provide all these facilities.

#include <iostream>
using namespace std;
class Patient {
    private:
        static int n;
        static double totalWeight;
        double weight;
    public:
        Patient() {
            weight = 60;
            n += 10;
            totalWeight += n * weight;
        }
        Patient(int ni, double wi) {
            weight = 60 + wi;
            n += ni;
            totalWeight += n * weight;
        }
        static void displayOverallAverage() {
            double overallAverage = totalWeight / n;
            cout << "Overall average weight of the group: " << overallAverage << " kg" << endl;
        }
};

int Patient::n = 0;
double Patient::totalWeight = 0;

int main() {
    Patient p1;
    Patient p2(5, 10);
    Patient::displayOverallAverage();

    return 0;
}
