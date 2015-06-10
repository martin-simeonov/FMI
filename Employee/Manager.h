#ifndef _MANAGER_H
#define _MANAGER_H

#include "Employee.h"
#include "List.cpp"

class Manager : public Employee{
	List<Employee*> workers_;
public:
	Manager(std::string, int, int);

	void addWorker(Employee&);
	void removeWorker(std::string);

	void printInfo();
};

#endif