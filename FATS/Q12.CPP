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
