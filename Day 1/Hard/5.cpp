#include <iostream>
using namespace std;

class Account {
protected:
    int balance;

public:
    virtual void calculateInterest() = 0;
    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double rate;
    int time;

public:
    SavingsAccount(int b, double r, int t) {
        balance = b;
        rate = r;
        time = t;
    }

    void calculateInterest() override {
        double interest = balance * (rate / 100) * time;
        cout << "Savings Account Interest: " << interest << endl;
    }
};

class CurrentAccount : public Account {
private:
    int maintenanceFee;

public:
    CurrentAccount(int b, int fee) {
        balance = b;
        maintenanceFee = fee;
    }

    void calculateInterest() override {
        balance -= maintenanceFee;
        cout << "Balance after fee deduction: " << balance << endl;
    }
};

int main() {
    int accountType;
    cout << "Enter account type (1 for Savings, 2 for Current): ";
    cin >> accountType;

    if (accountType == 1) {
        int balance, time;
        double rate;
        cout << "Enter balance: ";
        cin >> balance;
        cout << "Enter interest rate (percentage): ";
        cin >> rate;
        cout << "Enter time (years): ";
        cin >> time;

        if (balance < 1000 || balance > 1000000 || rate < 1 || rate > 15 || time < 1 || time > 10) {
            cout << "Invalid input values." << endl;
            return 1;
        }

        SavingsAccount savings(balance, rate, time);
        savings.calculateInterest();
    } else if (accountType == 2) {
        int balance, fee;
        cout << "Enter balance: ";
        cin >> balance;
        cout << "Enter maintenance fee: ";
        cin >> fee;

        if (balance < 1000 || balance > 1000000 || fee < 50 || fee > 500) {
            cout << "Invalid input values." << endl;
            return 1;
        }

        CurrentAccount current(balance, fee);
        current.calculateInterest();
    } else {
        cout << "Invalid account type." << endl;
    }

    return 0;
}
