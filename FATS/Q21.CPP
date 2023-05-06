#include <iostream>
using namespace std;

// Define the Mammals class
class Mammals {
public:
    void mammal_func() {
        cout << "I am a mammal" << endl;
    }
};

// Define the MarineAnimals class
class MarineAnimals {
public:
    void marine_func() {
        cout << "I am a marine animal" << endl;
    }
};

// Define the BlueWhale class which inherits from Mammals and MarineAnimals
class BlueWhale : public Mammals, public MarineAnimals {
public:
    void bluewhale_func() {
        cout << "I belong to both the categories: Mammals as well as Marine Animals" << endl;
    }
};

int main() {
    // Create objects
    Mammals mammal_obj;
    MarineAnimals marine_obj;
    BlueWhale bluewhale_obj;

    // Call functions of each class
    mammal_obj.mammal_func();   // Output: I am a mammal
    marine_obj.marine_func();   // Output: I am a marine animal
    bluewhale_obj.bluewhale_func();  // Output: I belong to both the categories: Mammals as well as Marine Animals

    // Call functions of parent classes using the BlueWhale object
    bluewhale_obj.mammal_func();    // Output: I am a mammal
    bluewhale_obj.marine_func();    // Output: I am a marine animal

    return 0;
}
