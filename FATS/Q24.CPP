#include <iostream>
using namespace std;

class Vehicle {
public:
    Vehicle() {
        cout << "Vehicle default constructor called" << endl;
    }
    Vehicle(int wheels) {
        cout << "Vehicle parameterized constructor called with wheels=" << wheels << endl;
    }
};

class TwoWheeler {
public:
    TwoWheeler() {
        cout << "TwoWheeler default constructor called" << endl;
    }
    TwoWheeler(int seats) {
        cout << "TwoWheeler parameterized constructor called with seats=" << seats << endl;
    }
};

class Bike : public Vehicle, public TwoWheeler {
public:
    Bike() {
        cout << "Bike default constructor called" << endl;
    }
    Bike(int wheels, int seats) : Vehicle(wheels), TwoWheeler(seats) {
        cout << "Bike parameterized constructor called with wheels=" << wheels << " and seats=" << seats << endl;
    }
};

int main() {
    cout << "Creating a Bike object using default constructor:" << endl;
    Bike b1;
    cout << endl;

    cout << "Creating a Bike object using parameterized constructor:" << endl;
    Bike b2(2, 2);
    cout << endl;

    return 0;
}
