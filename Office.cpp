#include "Office.h"

Office::Office() {}

Office::Office(std::string name, int age, int hours, std::string email, float salary)
: Employee(name, age, hours), email(email), salary(salary) {}

Office::~Office() {}

void Office::print() {
    std::cout << "Name: " << name << " Age: " << age << " Hours: " << hours << " Email: " << email << " Salary: " << salary << std::endl;
}

std::string Office::save() {
    std::stringstream ss;

    std::replace(name.begin(), name.end(), ' ', '-');
    ss << "Office" << " " << name << " " << age
    << " " << hours << " " << email << " " << salary << std::endl;

    std::replace(name.begin(), name.end(), '-', ' ');

    return ss.str();
}
