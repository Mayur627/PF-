#include <iostream>
#include <string>
#include <vector>

using namespace std;


const int PIN = 5467; 
const int MAXIMUM_ATTEMPTS = 5;   


bool authenticate(int &pinAttempts);
void showMenu();
void checkBalance(double balance);
void deposit(double &balance);
void withdraw(double &balance);

int main() {

    int pinAttempts = 0;  
    double balance = 1000.0;  
    int choice;

    
    if (!authenticate(pinAttempts)) {
        cout << "\t\t\tToo many incorrect attempts. Access denied!" << endl;
        return 0; 
    }

    
    do {
        showMenu();
        cin >> choice;


        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                deposit(balance);
                break;
            case 3:
                withdraw(balance);
                break;
            case 4:
                cout << "\t\t\tThank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "\t\t\tInvalid choice. Please select a valid option." << endl;
                break;
        }

    } while (choice != 4); 

    return 0;
}


bool authenticate(int &pinAttempts) {
    int enteredPin;
    while (pinAttempts < MAXIMUM_ATTEMPTS) {
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (enteredPin == PIN) {
            cout << "Authentication successful!" << endl;
            return true;  
        } else {
            pinAttempts++;
            cout << "Incorrect PIN. You have " << (MAXIMUM_ATTEMPTS - pinAttempts) << " attempts left." << endl;
        }
    }
    return false;  
}


void showMenu() {

  cout << "\t\t\t---------------------------------------" << endl;
    cout << "\t\t\t|   **AUTOMED TELLER MACHINE**        |" << endl;
    cout << "\t\t\t---------------------------------------" << endl;
    cout << "\t\t\t| 1. CHECK BALANCE                    |" << endl;
    cout << "\t\t\t| 2. DEPOSIT                          |" << endl;
    cout << "\t\t\t| 3. WITHDRAW                         |" << endl;
    cout << "\t\t\t| 4. EXIT                             |" << endl;
    cout << "\t\t\t---------------------------------------" << endl;
    cout << "\n\n\t\t\tPlease Enter your choice: ";
}


void checkBalance(double balance) {
    cout << "\t\t\tYour current balance is: $" << balance << endl;
}


void deposit(double &balance) {
    double amount;
    cout << "\t\t\tEnter the amount to deposit: $";
    cin >> amount;
    if (amount > 0) {
        balance += amount;
        cout << "\t\t\tSuccessfully deposited $" << amount << ". New balance: $" << balance << endl;
    } else {
        cout << "\t\t\tInvalid amount. Deposit must be positive." << endl;
    }
}


void withdraw(double &balance) {
    double amount;
    cout << "\t\t\tEnter the amount to withdraw: $";
    cin >> amount;

    if (amount <= balance) {
        if (amount > 0) {
            balance -= amount;
            cout << "\t\t\tSuccessfully withdrew $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "\t\t\tInvalid amount. Withdrawal must be positive." << endl;
        }
    } else {
        cout << "\t\t\tInsufficient balance. Withdrawal denied." << endl;
    }
}

