#pragma once

#include <vector>
#include <string>
#include <typeinfo>


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

    void add(Employee* e);
};
