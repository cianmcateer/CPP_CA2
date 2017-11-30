#include "util.h"
/**
* Will loop until an integer is entered
* @param choice
*/
void switch_validate(int& choice) {
    while(!(std::cin >> choice)) { // Input validation only accepts integers
        std::cout << "Sorry please enter a number" << std::endl;
        std::cin.clear();
        std::cin.ignore(100,'\n'); // Stops message from printing more than once if user enters more than one character
    }
}

void create_account(std::string name, std::string password) {

    std::replace(name.begin(), name.end(), ' ', '-');
    std::replace(password.begin(), password.end(), ' ', '-');

    Account a(name, password);
    std::ofstream account_file("accounts.txt",std::fstream::in | std::ios::out | std::ios::app);
    if(account_file.is_open()) {
        account_file << a;
        std::cout << a.get_name().substr(0,a.get_name().find('-')) << " has been added to accounts" << std::endl;
    } else {
        std::cerr << "Could not open account file" << std::endl;
    }
}

std::vector<Account> get_users() {
    std::ifstream account_file("accounts.txt");
    std::vector<Account> accounts;
    if(account_file.is_open()) {

        Account a;
        std::vector<std::string> lines;

        std::string line;
        while(getline(account_file, line)) {
            lines.push_back(line);
        }
        for(unsigned int i = 0;i < lines.size();++i) {
            std::stringstream ss(lines[i]);

            while(ss >> a) {
                Account formatted_account = read_account(a);
                accounts.push_back(formatted_account);
            }
        }

    } else {
        std::cerr << "Cannot open account file" << std::endl;
    }
    return accounts;
}

Account read_account(Account& a) {
    std::string name = a.get_name();
    std::string password = a.get_password();

    std::replace(name.begin(), name.end(), '-', ' ');
    std::replace(password.begin(), password.end(), '-', ' ');

    a.set_name(name);
    a.set_password(password);

    return a;
}

/**
* Displays the contents of the file path passed in
* @param path
*/
void display_file(const std::string path) {
    // Fix file path problem
    std::ifstream help_menu(path);
    if(help_menu.is_open()) {
        std::string line;
        // Will read line until new line is detected
        while(std::getline(help_menu,line)) {
            std::cout << line << std::endl;
        }
    } else {
        std::cerr << "Error opening menu file" << std::endl;
    }

}

/**
* Returns substring of input cut off by whitespace character
* @author Cian McAteer
* @param user
* @return string
*/
std::string firstName(std::string user) {
    return user.substr(0,user.find(' '));
}
