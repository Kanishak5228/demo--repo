#include <iostream>
#include <cstring>

using namespace std;

class String {
    private:
        char *str;
        int len;
    public:
        String() {
            len = 0;
            str = new char[len+1];
            str[0] = '\0';
        }
        String(const char *s) {
            len = strlen(s);
            str = new char[len+1];
            strcpy(str, s);
        }
        String(const String &s) {
            len = s.len;
            str = new char[len+1];
            strcpy(str, s.str);
        }
        ~String() {
            delete [] str;
        }
        void display() {
            cout << str << endl;
        }
        String operator+(String s) {
            String temp;
            temp.len = len + s.len;
            temp.str = new char[temp.len+1];
            strcpy(temp.str, str);
            strcat(temp.str, s.str);
            return temp;
        }
        bool operator==(String s) {
            return (strcmp(str, s.str) == 0);
        }
};

int main() {
    String s1("Hello");
    String s2("World");
    String s3 = s1 + s2;
    s1.display();
    s2.display();
    s3.display();
    if(s1 == s2) {
        cout << "Strings are equal" << endl;
    } else {
        cout << "Strings are not equal" << endl;
    }
    return 0;
}
