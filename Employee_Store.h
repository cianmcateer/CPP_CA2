#pragma once

#include <vector>
#include <string>
#include <typeinfo>
#include <fstream>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

#include "Employee.h"
#include "Office.h"
#include "Factory.h"
#include "util.h"

class Employee_Store {

private:
    std::vector<Employee*> employeeStore;
    std::vector<Employee*> load();
    std::vector<Employee*> read(std::string path);
    std::stack<std::string> readLog();

    std::string getTime();
    std::set<Employee*> getRecords();

    template <class T>
    float average(std::vector<T>& vec) {
        if(vec.empty()) {
            return 0;
        } else {
            int total = 0;
            for(const auto& v : vec) {
                total += v;
            }
            return total / vec.size();
        }
    }

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
    void updateEmployee(int& employee_type);

    void save(std::string fileName);

    void history();
    void show_history();

    void printEmployees(bool type);

    void displayLogs();
    void createWebpage();

    void sortEmployees();

    float averagePayment();
    float averageHours();

    friend std::ostream& operator<<(std::ostream& output_stream, const Employee_Store& et);

};
