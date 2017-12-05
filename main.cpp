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


#define DEBUG false

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

void init();
void menu(string user);

int main(void) {
    DEBUG ? menu("tester") : init();
    return 0;
}

void init() {
    cout << "Hello, Welcome to office block, your employee storage system!" << endl;
    int choice;
    cout << "Are you new? 0 = exit, 1 = yes, 2 = no" << endl;

    switch_validate(choice);

    //while(true) {
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
                string name;
                cin.ignore();
                std::getline(cin, name);
                vector<Account> users = get_users();

                for(auto& u : users) {
                    if(u.get_name() == name) {
                        menu(name);
                    }
                }
                break;
            }
            default:
                cout << "Invalid number (0 = exit, 1 = yes, 2 = no)" << endl;
                break;
        }
    //}

}

void menu(string user) {
    cout << "Welcome " << firstName(user) << "!" << endl;
    int choice;

    std::replace(user.begin(), user.end(), ' ', '_');
    Employee_Store et("users/"+user+".txt");
    std::replace(user.begin(), user.end(), '_', ' ');
    while(true) {
        display_file("menus/main_menu.txt");
        switch_validate(choice);
        switch(choice) {
            case 0: {
                cout << "Goodbye!" << endl;
                return;
                break;
            }

            case 1: {
                cout << "Print all employees" << endl;
                et.print();
                break;
            }

            case 2: {
                cout << "Display employees sorted by one of the following properties" << endl;
                display_file("menus/sort_menu.txt");
                int sort_by;
                switch_validate(sort_by);

                switch(sort_by) {

                    case 1: {

                        break;
                    }

                    case 2: {
                        break;
                    }

                    case 3: {
                        break;
                    }
                }

                break;
            }

            case 3: {
                et.printEmployees(true);
                break;
            }

            case 4: {
                et.printEmployees(false);
                break;
            }

            case 5: {
                cout << "Add employee" << endl;
                cout << "please enter 1 for factory worker, 2 for office staff" << endl;
                int employee_type;
                switch_validate(employee_type);

                cout << "Enter name" << endl;
                string name;
                cin.ignore();
                std::getline(cin, name);

                cout << "Enter age" << endl;
                int age;
                cin >> age;

                cout << "Enter hours" << endl;
                int hours;
                cin >> hours;

                if(employee_type == 1) {
                    cout << "Enter wage of worker" << endl;
                    float wage;
                    cin >> wage;

                    Factory* f = new Factory(name, age, hours, wage);
                    et.add(f);
                }
                if(employee_type == 2) {
                    cout << "Enter staff email" << endl;
                    cin.ignore();
                    string email;
                    std::getline(cin, email);

                    cout << "Enter staff salary" << endl;
                    float salary;
                    cin >> salary;

                    Office* o = new Office(name, age, hours, email, salary);
                    et.add(o);
                }
                break;
            }

            case 6: {
                cout << "Delete employee." << endl;
                cout << "Please choose from one of the following employees, enter index of employee you wish to remove. Enter -1 to abort" << endl;
                et.show_index();
                int index;
                switch_validate(index);

                if(index == -1) {
                    cout << "Deletion aborted" << endl;
                    break;
                }
                while(index < -1 || !et.inRange(index)) {

                    if(index < -1) {
                        std::cerr << "Please enter a positive value or enter -1 to abort deletion" << endl;
                        switch_validate(index);
                    }
                    if(!et.inRange(index)) {
                        std::cerr << "You have entered an integer that is out of range" << endl;
                        switch_validate(index);
                    }
                }
                et.erase(index);
                break;
            }

            case 7: {

                cout << "Update employee" << endl;
                et.updateEmployee();
                break;
            }
            case 8: {
                std::replace(user.begin(), user.end(), ' ', '_');
                string filePath = "users/"+user+".txt";
                et.save(filePath);
                std::replace(user.begin(), user.end(), '_', ' ');
                break;
            }
            default:
                cout << "Invalid number" << endl;
                break;
        }
    }
}
