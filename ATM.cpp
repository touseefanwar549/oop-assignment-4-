#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    double balance;

public:
    // Constructor
    BankAccount(string n, double b) {
        cout << "Constructor called..." << endl;
        if (b < 0) {
            throw invalid_argument("Invalid account creation: Negative balance not allowed.");
        }
        name = n;
        balance = b;
        cout << "Account created successfully for " << name << endl;
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount > balance) {
            throw runtime_error("Withdrawal failed: Insufficient balance.");
        }
        balance -= amount;
        cout << "Withdrawal successful. Remaining balance: " << balance << endl;
    }

    // Destructor
    ~BankAccount() {
        cout << "Destructor called... Account cleaned up." << endl;
    }
};

int main() {
    BankAccount* acc = nullptr;

    try {
        acc = new BankAccount("Ali", 500);   // Valid creation
        acc->withdraw(200);                 // Valid withdrawal
        acc->withdraw(400);                 // Invalid withdrawal
    }
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    // Safe cleanup
    delete acc;

    cout << "Program ended safely." << endl;
    return 0;
}
