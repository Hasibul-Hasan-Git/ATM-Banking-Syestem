#include <iostream>
#include <string>
using namespace std;

class ATM {
private:
    string username;
    string password;
    double balance;

public:
    ATM(string user, string pass, double initialBalance) : username(user), password(pass), balance(initialBalance) {}

    bool login(string user, string pass) {
        if (username == user && password == pass) {
            cout << "Login successful!\n";
            return true;
        } else {
            cout << "Invalid username or password.\n";
            return false;
        }
    }

    void displayBalance() {
        cout << "Your current balance is: $" << balance << "\n";
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "$" << amount << " deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "$" << amount << " withdrawn successfully.\n";
        } else {
            cout << "Invalid withdrawal amount or insufficient funds.\n";
        }
    }

    void showMenu() {
        cout << "\nATM Menu:\n";
        cout << "1. Display Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
    }
};

int main() {
    string username, password;
    cout << "Welcome to the ATM System\n";
    cout << "Set up your account.\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ATM atm(username, password, 0.0);

    cout << "\nPlease login to continue.\n";
    string loginUser, loginPass;
    while (true) {
        cout << "Enter username: ";
        cin >> loginUser;
        cout << "Enter password: ";
        cin >> loginPass;

        if (atm.login(loginUser, loginPass)) {
            break;
        }
    }

    int choice;
    while (true) {
        atm.showMenu();
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            atm.displayBalance();
            break;
        case 2: {
            double depositAmount;
            cout << "Enter amount to deposit: ";
            cin >> depositAmount;
            atm.deposit(depositAmount);
            break;
        }
        case 3: {
            double withdrawAmount;
            cout << "Enter amount to withdraw: ";
            cin >> withdrawAmount;
            atm.withdraw(withdrawAmount);
            break;
        }
        case 4:
            cout << "Thank you for using the ATM. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}