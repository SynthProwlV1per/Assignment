#include <iostream>
#include <string>
using namespace std;

// Global variables for account information
string username = "student";
string password = "123";
string accountName = "Mr Owami";
double balance = 500.00; // Starting balance in Rands

// Function declarations
void login();
void checkBalance();
void deposit();
void withdraw();
void sendMoney();
void displayMenu();
void login() {
    string inputUsername, inputPassword;

    cout << "=== Banking System ===" << endl;
    cout << "Login:" << endl;
    cout << "Username: ";
    cin >> inputUsername;
    cout << "Password: ";
    cin >> inputPassword;

    if (inputUsername == username && inputPassword == password) {
        cout << "Login Successful!" << endl;
        displayMenu();
    } else {
        cout << "Error: Invalid username or password. Program ending." << endl;
    }
}

void displayMenu() {
    int choice;

    do {
        cout << "\n=== MAIN MENU ===" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Send Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                sendMoney();
                break;
            case 5:
                cout << "Thank you for using our banking system!" << endl;
                break;
            default:
                cout << "Error: Invalid menu choice. Please try again." << endl;
        }
    } while (choice != 5);
}

void checkBalance() {
    cout << "Balance: R" << balance << endl;
    cout << "Account: " << accountName << endl;
}

void deposit() {
    double amount;
    cout << "Enter deposit amount: R";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful! New balance: R" << balance << endl;
    } else {
        cout << "Error: Invalid deposit amount." << endl;
    }
}

void withdraw() {
    double amount;
    cout << "Enter withdrawal amount: R";
    cin >> amount;

    if (amount > 0) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! New balance: R" << balance << endl;
        } else {
            cout << "Error: Insufficient funds." << endl;
        }
    } else {
        cout << "Error: Invalid withdrawal amount." << endl;
    }
}

void sendMoney() {
    string recipient;
    double amount;

    cout << "Enter recipient name: ";
    cin >> recipient;
    cout << "Enter transfer amount: R";
    cin >> amount;

    if (amount > 0) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Transfer of R" << amount << " to " << recipient << " successful!" << endl;
            cout << "New balance: R" << balance << endl;
        } else {
            cout << "Error: Insufficient funds for transfer." << endl;
        }
    } else {
        cout << "Error: Invalid transfer amount." << endl;
    }
}
int main() {
    login();
    return 0;
}


