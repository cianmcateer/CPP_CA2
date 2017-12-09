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
    display_file("menus/login.txt");

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
                et.sortEmployees();
                break;
            }

            case 3: {
                cout << "Show " << endl;
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
                std::string nameRegex = "[a-z\A-Z ,.'-]+$";
                string name;
                cin.ignore();
                std::getline(cin, name);

                while(!regexValidate(name, nameRegex)) {
                    cout << "Incorrect name input (No special characters or digits)" << endl;
                    cin.clear();
                    std::getline(cin, name);
                }

                cout << "Enter age" << endl;
                int age;
                switch_validate(age);

                ageRestriction(age);

                cout << "Enter hours" << endl;
                int hours;
                switch_validate(hours);

                while(hours > 48) {
                    cout << "Legally, the weekly working limit is 48 hours or under, please try again" << endl;
                    cin.clear();
                    switch_validate(hours);
                }


                if(employee_type == 1) {
                    cout << "Enter wage of worker" << endl;
                    float wage;
                    cin >> wage;

                    const float min_wage = 9.25;

                    while((wage / hours) < min_wage) {
                        cout << name << " is being underpayed, please enter a higher value." << endl;
                        cout << "Minimum payment: " << hours * min_wage << "!" << endl;
                        cin.clear();
                        cin >> wage;
                    }

                    Factory* f = new Factory(name, age, hours, wage);
                    et.add(f);

                    std::string message = "Factory worker, '" + name + "' was added by " + user + " on";
                    addLog(message);
                }
                if(employee_type == 2) {
                    cout << "Enter staff email" << endl;
                    cin.ignore();
                    string email;
                    std::getline(cin, email);

                    const std::string emailRegex = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+";
                    while(!regexValidate(email, emailRegex)) {
                        cout << "Invalid email address" << endl;
                        cin.clear();
                        std::getline(cin, email);
                    }
                    cout << "Enter staff salary" << endl;
                    float salary;
                    cin >> salary;

                    const float min_wage = 9.25;
                    while((salary / hours) < min_wage) {
                        cout << firstName(name) << " is being underpayed, please enter a higher value." << endl;
                        cout << "Minimum payment: " << hours * min_wage << "!" << endl;
                        cin.clear();
                        cin >> salary;
                    }

                    Office* o = new Office(name, age, hours, email, salary);
                    et.add(o);

                    std::string message = "Office worker, '" + name + "' was added by " + user + " on";
                    addLog(message);
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
                addLog("Employee was deleted by " + user + " on");
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
                addLog(user + " altered his save data on ");

                et.history();
                addLog(user + " Added data to records");
                break;
            }
            case 9 : {
                et.createWebpage();
                cout << "Your webpage has been created" << endl;
                break;
            }
            case 10 : {
                cout << "Logs display" << endl;
                et.displayLogs();
                break;
            }
            case 11 : {
                et.show_history();
                break;
            }
            default:
                cout << "Invalid number" << endl;
                break;
        }
    }
}
