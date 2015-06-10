#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>

class Employee
{
	std::string name_;
	int service_;
	int salary_;
public:
	Employee(std::string, int, int);
	Employee();

	std::string getName() const;
	int getService() const;
	int getSalary() const;
	Employee& setService(int);
	Employee& setSalary(int);

	virtual void printInfo();
};

#endif