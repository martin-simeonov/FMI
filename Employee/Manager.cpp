#include "Manager.h"
#include <iostream>

Manager::Manager(std::string name, int service, int salary)
: Employee(name, service, salary)
{}

void Manager::addWorker(Employee& e)
{
	workers_.push_back(&e);
}

void Manager::removeWorker(std::string name)
{
	for (List<Employee*>::iterator it = workers_.begin(); it != workers_.end(); it++)
	{
		if ((*(*it)).getName().compare(name) == 0)
		{
			workers_.erase(it);
		}
	}
}

void Manager::printInfo()
{
	Employee::printInfo();
	std::cout << ", Manages " << workers_.size() << " people:" << std::endl;
	for (List<Employee*>::iterator it = workers_.begin(); it != workers_.end(); it++)
	{
		std::cout << "\t";
		(*(*it)).printInfo();
		std::cout << std::endl;
	}
}