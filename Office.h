#include <iostream>
#include <string>

#include "Employee.h"

class Office: public Employee {

private:
    std::string email;
    float salary;

public:

    void print();
    Office();
    Office(std::string name, int age, int hours, std::string email, float salary);
    virtual ~Office();

    inline std::string getEmail() const {
        return email;
    }

    inline float getSalary() const {
        return salary;
    }

    inline void setEmail(std::string email) {
        this->email = email;
    }

    inline void setSalary(float salary) {
        this->salary = salary;
    }

};
