#include "Account.h"

Account::Account(std::string user_name, std::string password):
user_name(user_name), password(password){}

Account::Account():
user_name("Default name"), password("Default Password"){}

Account::~Account(){}

/**
* Output stream will be used to write Accounts to a file
*/
std::ostream& operator<<(std::ostream& output_stream, const Account& a) {
    output_stream << a.user_name << "," << a.password << std::endl;
    return output_stream;
}

std::istream& operator>>(std::istream& input_stream, Account& a) {

    std::string user_name;
    input_stream >> user_name;
    a.set_user_name(user_name);

    std::string password;
    input_stream >> password;
    a.set_password(password);

    return input_stream;
}
