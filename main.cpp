// C++ CA2 Cian McAteer Ciaran Maher
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "Account.h"
#include "Employee_Store.h"
#include "util.h"


using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

void init();
void menu(string& user);

int main(void) {
    init();
    return 0;
}

void init() {
    cout << "Hello, Welcome to office block, your employee storage system!" << endl;
    int choice;
    cout << "Are you new? 0 = exit, 1 = yes, 2 = no" << endl;

    switch_validate(choice);
    switch (choice) {
        case 0: {
            cout << "Goodbye!" << endl;
            return;
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
            vector<Account> users = get_users();


            break;
        }
        default:
            cout << "Invalid number (0 = exit, 1 = yes, 2 = no)" << endl;
            break;
    }
}

void menu(string& user) {
    int choice;

    Employee_Store et;
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
