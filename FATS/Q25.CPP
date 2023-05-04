#include <iostream>

using namespace std;

class Complex {
    private:
        double real;
        double imag;
    
    public:
        Complex() {
            real = 0;
            imag = 0;
        }
        
        Complex(double r, double i) {
            real = r;
            imag = i;
        }
        
        friend Complex operator+(const Complex& c1, const Complex& c2);
        
        void display() {
            cout << real << " + " << imag << "i" << endl;
        }
};

Complex operator+(const Complex& c1, const Complex& c2) {
    double r = c1.real + c2.real;
    double i = c1.imag + c2.imag;
    return Complex(r, i);
}

int main() {
    Complex c1(2.5, 3.7);
    Complex c2(1.2, 2.9);
    Complex c3 = c1 + c2;
    
    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();
    cout << "c1 + c2 = ";
    c3.display();
    
    return 0;
}
