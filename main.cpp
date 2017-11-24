// C++ CA2 Cian McAteer Ciaran Maher
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void init();
void menu();
void switch_validate(int& choice);

int main(void) {
    init();
}

void init() {
    cout << "Hello" << endl;
    menu();
}

void menu() {
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
