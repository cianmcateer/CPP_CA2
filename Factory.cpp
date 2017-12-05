#include "Factory.h"

Factory::Factory(std::string name, int age, int hours, float wage)
: Employee(name, age, hours), wage(wage) {}

Factory::Factory() {}

Factory::~Factory() {}


void Factory::print() {
    std::cout << "Name: " << name << " Age: " << age << " Hours: " << hours << " Wages: " << wage << std::endl;
}

std::string Factory::save() {
    std::stringstream ss;

    std::replace(name.begin(), name.end(), ' ', '-');
    ss << "Factory" << " " << name << " " << age
    << " " << hours << " " << wage << std::endl;

    std::replace(name.begin(), name.end(), '-', ' ');
    return ss.str();
}
