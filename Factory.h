#pragma once

#include "Employee.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

/**
* @author Ciaran Maher
*/
class Factory : public Employee {
private:
		float wage;
public:
	void print();
    Factory();
    Factory(std::string name, int age, int hours, float wage);

	std::string save();
    ~Factory();

	void extract_data(std::ostream& out);

    inline float getWage() const {
        return wage;
    }

    inline void setWage(float wage) {
        this->wage = wage;
    }



};
