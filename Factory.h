#pragma once
#include <iostream>

#include "Employee.h"

class Factory: public Employee {
private:
		float wage;
public:
	void print();
    Factory();
    Factory(std::string name, int age, int hours, float wage);
    virtual ~Factory();

	void extract_data(std::ostream& out);

    inline float getWage() const {
        return wage;
    }

    inline void setWage(float wage) {
        this->wage = wage;
    }
	std::string save();
};
