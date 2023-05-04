#include <iostream>

using namespace std;

class Time {
    private:
        int hours;
        int minutes;
        int seconds;
    
    public:
        Time() {
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
        
        Time(int h, int m, int s) {
            hours = h;
            minutes = m;
            seconds = s;
        }
        
        void setTime(int h, int m, int s) {
            hours = h;
            minutes = m;
            seconds = s;
        }
        
        void displayTime() {
            cout << hours << ":" << minutes << ":" << seconds << endl;
        }
        
        bool operator==(const Time& t) const {
            return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);
        }
};

int main() {
    Time t1(10, 30, 45);
    Time t2(10, 30, 45);
    Time t3(12, 15, 30);
    
    cout << "Time 1: ";
    t1.displayTime();
    cout << "Time 2: ";
    t2.displayTime();
    cout << "Time 3: ";
    t3.displayTime();
    
    if (t1 == t2) {
        cout << "Time 1 and Time 2 are the same." << endl;
    } else {
        cout << "Time 1 and Time 2 are different." << endl;
    }
    
    if (t1 == t3) {
        cout << "Time 1 and Time 3 are the same." << endl;
    } else {
        cout << "Time 1 and Time 3 are different." << endl;
    }
    
    return 0;
}
