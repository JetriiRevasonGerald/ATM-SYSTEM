#include <iostream>
#include <string>
using namespace std;

class ATM {
private:
    int pin;
    double balance;

public:
    // Constructor to initialize ATM object with a default PIN and balance
    ATM() {
        pin = 1234;  // Default PIN
        balance = 1000.00;  // Default balance
    }

    // Method to check balance
    void checkBalance() {
        cout << "Your current balance is: $" << balance << endl;
    }

    // Method to withdraw money
    void withdrawMoney() {
        double amount;
        cout << "Enter amount to withdraw: $";
        cin >> amount;

        if (amount <= balance) {
            balance -= amount;
            cout << "Transaction successful! You withdrew: $" << amount << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    // Method to deposit money
    void depositMoney() {
        double amount;
        cout << "Enter amount to deposit: $";
        cin >> amount;
        balance += amount;
        cout << "Transaction successful! You deposited: $" << amount << endl;
    }

    // Method to change PIN
    void changePIN() {
        int newPin;
        cout << "Enter new PIN: ";
        cin >> newPin;
        pin = newPin;
        cout << "PIN changed successfully!" << endl;
    }

    // Method to verify PIN
    bool verifyPIN(int enteredPin) {
        return enteredPin == pin;
    }
};

int main() {
    ATM myATM;
    int enteredPin;
    int choice;

    cout << "Welcome to the ATM simulation!" << endl;

    // PIN verification loop
    cout << "Please enter your PIN: ";
    cin >> enteredPin;

    if (!myATM.verifyPIN(enteredPin)) {
        cout << "Incorrect PIN! Access denied." << endl;
        return 0;  // Exit if PIN is wrong
    }

    // Main menu
    do {
        cout << "\nATM Menu: \n";
        cout << "1. Check Balance\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Deposit Money\n";
        cout << "4. Change PIN\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
        case 1:
            myATM.checkBalance();
            break;
        case 2:
            myATM.withdrawMoney();
            break;
        case 3:
            myATM.depositMoney();
            break;
        case 4:
            myATM.changePIN();
            break;
        case 5:
            cout << "Thank you for using the ATM. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}