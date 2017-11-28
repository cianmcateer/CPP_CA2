#include "Employee_Store.h"

Employee_Store::Employee_Store() {
    this->employeeStore = load();
}

std::vector<Employee*> Employee_Store::load() {

    Office* o1 = new Office("Cian McAteer", 22, 40,"cian@email.com", 1200);
    Office* o2 = new Office("John Smith", 27, 35, "john@email.com", 1600);
    Office* o3 = new Office("Matthew McCardle", 44, 38, "matthew@email", 1500);
    Office* o4 = new Office("Jamie Simmons", 30, 25, "jamie@email.com", 900);

    Factory* f1 = new Factory("Barry Smith", 19, 45, 420);
    Factory* f2 = new Factory("Michael Sweeney", 21, 30, 270);
    Factory* f3 = new Factory("Phil Bowlington", 18, 20, 210);
    Factory* f4 = new Factory("Carl Bingham", 25, 10, 400);

    std::vector<Employee*> backup;
    backup.push_back(o1);
    backup.push_back(o2);
    backup.push_back(o3);
    backup.push_back(o4);

    backup.push_back(f1);
    backup.push_back(f2);
    backup.push_back(f3);
    backup.push_back(f4);

    return backup;
}

inline std::vector<Employee*> Employee_Store::getEmployeeStore() const {
    return employeeStore;
}

void Employee_Store::print() {
    std::cout << "Current number of employees: " << employeeStore.size() << "." << std::endl;
    for(Employee* e : employeeStore) {
        e->print();
    }
}

Employee_Store::~Employee_Store() {
    for(Employee* e : employeeStore) {
        delete e;
    }
    employeeStore.clear();
}

void Employee_Store::add(Employee* e) {
    employeeStore.push_back(e);
}

bool Employee_Store::inRange(int& i) {
    return i < employeeStore.size();
}

void Employee_Store::show_index() {
    for(unsigned int i = 0;i < employeeStore.size();++i) {
        std::cout << "Index: " << i << " Name: " << employeeStore[i]->getName() << "." << std::endl;
    }
}

void Employee_Store::erase(int& index) {
    employeeStore.erase(employeeStore.begin() + index);
}
