#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class BankCustomer {
private:
    string name;
    int accountNumber;
    string accountType;
    string status;
    double balance;
    time_t lastTransactionDate;

public:
    // Constructor
    BankCustomer(string name, int accountNumber, string accountType, string status, double balance, time_t lastTransactionDate) {
        this->name = name;
        this->accountNumber = accountNumber;
        this->accountType = accountType;
        this->status = status;
        this->balance = balance;
        this->lastTransactionDate = lastTransactionDate;
    }

    // Getters
    string getName() {
        return name;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getAccountType() {
        return accountType;
    }

    string getStatus() {
        return status;
    }

    double getBalance() {
        return balance;
    }

    time_t getLastTransactionDate() {
        return lastTransactionDate;
    }

    // Setters
    void setName(string name) {
        this->name = name;
    }

    void setAccountType(string accountType) {
        this->accountType = accountType;
    }

    void setStatus(string status) {
        this->status = status;
    }

    // Other member functions
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Status: " << status << endl;
        cout << "Balance: " << balance << endl;
        cout << "Last Transaction Date: " << ctime(&lastTransactionDate) << endl;
    }

    void withdraw(double amount) {
        if (balance - amount < 1000) {
            cout << "Withdrawal denied! Balance cannot be less than 1000." << endl;
        } else {
            balance -= amount;
            lastTransactionDate = time(NULL);
            cout << "Withdrawal successful!" << endl;
        }
    }

    void updateStatus() {
        time_t currentTime = time(NULL);
        double timeDiff = difftime(currentTime, lastTransactionDate);
        if (timeDiff >= 31536000) { // 1 year in seconds
            status = "Dormant";
            cout << "Account status changed to Dormant." << endl;
        }
    }
};

int main() {
    // Create a BankCustomer object
    BankCustomer customer1("John Doe", 12345, "Savings", "Active", 5000.0, time(NULL));

    // Display customer details
    cout << "Customer Details: " << endl;
    customer1.displayDetails();

    // Withdraw funds
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    customer1.withdraw(amount);
    customer1.displayDetails();

    // Update account status
    customer1.updateStatus();
    customer1.displayDetails();

    return 0;
}
