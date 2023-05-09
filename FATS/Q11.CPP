#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string n;
    void displayPerson() {
        cout << "name -  " << n << endl;
    }
};

class Account : virtual public Person {
public:
    float p;
    void displayPay() {
        cout << "pay amnt -  " << p << endl;
    }
};

class Admin : virtual public Person {
public:
    int e;
    void displayExperience() {
        cout << "exp -  " << e << endl;
    }
};

class Master : public Account, public Admin {
public:
    void disp() {
        displayPerson();
        displayPay();
        displayExperience();
    }
};

int main() {
    Master x;
    x.n = "xyz";
    x.p = 327.23;
    x.e = 8;
    x.disp();
    return 0;
}