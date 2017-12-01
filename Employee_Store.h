#pragma once

#include <vector>
#include <string>
#include <typeinfo>
#include <fstream>


#include "Employee.h"
#include "Office.h"
#include "Factory.h"

class Employee_Store {

private:
    std::vector<Employee*> employeeStore;
    std::vector<Employee*> load();
public:
    Employee_Store();
    ~Employee_Store();


    void print();

    std::vector<Employee*> getEmployeeStore() const;

    bool inRange(int& index);
    void add(Employee* e);
    void show_index();
    void erase(int& index);
    void clear();
    void updateEmployee();

    std::string save();
    void saveChanges(std::string fileName);
    void printEmployees(bool type);

};
