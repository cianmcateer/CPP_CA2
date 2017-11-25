#pragma once

#include <string>
#include <iostream>
#include <ostream>
#include <istream>

class Account {
private:
    std::string user_name;
    std::string password;

public:
    Account(std::string user_name, std::string password);
    Account();
    ~Account();

    inline std::string get_user_name() const {
        return user_name;
    }

    inline std::string get_password() const {
        return password;
    }

    inline void set_user_name(std::string user_name) {
        this->user_name = user_name;
    }

    inline void set_password(std::string password) {
        this->password = password;
    }

    friend std::ostream& operator<<(std::ostream& output_stream, const Account& a);
    friend std::istream& operator>>(std::istream& input_stream, const Account& a);
};
