#include <iostream>
using namespace std;

class A {
public:
    int x;
};

class B : virtual public A {
public:
    int y;
};

class C : virtual public A {
public:
    int z;
};

class D : public B, public C {
public:
    int w;
};

int main() {
    D d;
    d.x = 10;
    d.y = 20;
    d.z = 30;
    d.w = 40;

    cout << "Values of x, y, z, and w in class D:" << endl;
    cout << d.x << ", " << d.y << ", " << d.z << ", " << d.w << endl;

    return 0;
}
