#pragma once
#include <iostream>
#include <string>

class Employee
{
	protected:
		std::string name;
		int age;
		int hours;

		Employee();
		Employee(std::string name, int age, int hours);

	public:
		virtual ~Employee(){}
		virtual void print()=0;

		inline void setName(std::string name)
		{
			this->name = name;
		}
		inline void setAge(int age)
		{
			this->age = age;
		}
		inline void setHours(int hours)
		{
			this->hours = hours;
		}

		inline std::string getName() const
		{
			return name;
		}
		inline float getAge() const
		{
			return age;
		}
		inline int getHours() const
		{
			return hours;
		}

		friend bool operator <(const Employee& e1, const Employee& e2);
};
