#include <iostream>

using namespace std;

class AddAmount {
    private:
        int amount;
    public:
        AddAmount() {
            amount = 50;
        }
        AddAmount(int amt) {
            amount = 50 + amt;
        }
        void displayAmount() {
            cout << "Amount in Piggie Bank: $" << amount << endl;
        }
};

int main() {
    AddAmount p1;
    AddAmount p2(100);
    p1.displayAmount();
    p2.displayAmount();

    return 0;
}
