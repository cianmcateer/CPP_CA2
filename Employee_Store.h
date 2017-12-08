#pragma once

#include <vector>
#include <string>
#include <typeinfo>
#include <fstream>
#include <algorithm>
#include <stack>
#include <set>

#include "Employee.h"
#include "Office.h"
#include "Factory.h"

class Employee_Store {

private:
    std::vector<Employee*> employeeStore;
    std::vector<Employee*> load();
    std::vector<Employee*> read(std::string path);
    std::stack<std::string> readLog();

    std::string getTime();
    std::set<Employee*> getRecords();

public:
    Employee_Store(std::string path);
    ~Employee_Store();

    void print();
    std::vector<Employee*> getEmployeeStore() const;

    bool inRange(int& index);
    void add(Employee* e);
    void show_index();
    void erase(int& index);
    void clear();
    void updateEmployee();

    void save(std::string fileName);

    void history();
    void show_history();

    void printEmployees(bool type);

    void displayLogs();
    void createWebpage();
};
