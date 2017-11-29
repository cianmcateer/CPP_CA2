#include "Factory.h"

Factory::Factory(std::string name, int age, int hours, float wage)
: Employee(name, age, hours), wage(wage) {}

Factory::Factory() {}
Factory::~Factory() {}


void Factory::print() {
    std::cout << "Name: " << name << " Age: " << age << " Hours: " << hours << " Wages: " << wage << std::endl;
}
