#ifndef _PERSONNEL_H
#define _PERSONNEL_H

#include "Employee.h"
#include "List.cpp"

class Personnel
{
	List <Employee*> workers_;
public:
	void addWorker(Employee&);
	void removeWorker(std::string);
	int calculateMonthlyCosts();
	void printWorkers();

	Employee& operator[](int index);
	int size();
};

#endif _PERSONNEL_H