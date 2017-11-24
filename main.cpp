// C++ CA2 Cian McAteer Ciaran Maher
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Account.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

void init();
void menu(string& user);
void password();

void switch_validate(int& choice);
void create_account(string& name, string& password);
vector get_users();

int main(void) {
    init();
}

void init() {
    cout << "Hello, Welcome to office block, your employee storage system!" << endl;
    int choice;
    cout << "Are you new? 0 = exit, 1 = yes, 2 = no" << endl;

    switch_validate(choice);
    switch (choice) {
        case 0: {
            cout << "Goodbye!" << endl;
            exit(0);
            break;
        }
        case 1: {
            cout << "Please create an account" << endl;

            cout << "Please enter user name" << endl;
            cin.ignore();
            string user_name;
            std::getline(cin, user_name);

            cin.clear();

            cout << "Now please enter password" << endl;
            string password;
            std::getline(cin, password);

            create_account(user_name, password);
            menu(user_name);
            break;
        }
        case 2: {
            cout << "Enter details" << endl;
            break;
        }
        default:
            cout << "Invalid number (0 = exit, 1 = yes, 2 = no)" << endl;
            break;
    }
}

void create_account(string& name, string& password) {
    Account a(name, password);
    std::ofstream account_file("accounts.txt",std::fstream::in | std::ios::out | std::ios::app);
    if(account_file.is_open()) {
        account_file << a;
        cout << a.get_user_name() << " has been added to accounts" << endl;
    } else {
        std::cerr << "Could not open account file" << endl;
    }
}

vector get_users() {
    std::ifstream account_file("accounts.txt");
    if(account_file.is_open()) {
        
    } else {
        std::cerr << "Cannot open account file" << endl;
    }
}

void menu(string& user) {
    int choice;

    while(true) {

        switch_validate(choice);

        switch(choice) {
            case 0: {
                cout << "Goodbye!" << endl;
                exit(0);
                break;
            }
            case 1: {
                cout << "Case 1" << endl;
                break;
            }
            case 2: {
                cout << "Case 2" << endl;
                break;
            }
            default:
                cout << "Invalid number" << endl;
                break;
        }
    }
}

/**
* Will loop until an integer is entered
* @param choice
*/
void switch_validate(int& choice) {
    while(!(cin >> choice)) { // Input validation only accepts integers
        cout << "Sorry please enter a number" << endl;
        cin.clear();
        cin.ignore(100,'\n'); // Stops message from printing more than once if user enters more than one character
    }
}
