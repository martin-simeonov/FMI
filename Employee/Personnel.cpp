#include "Personnel.h"
#include <iostream>

void Personnel::addWorker(Employee& e)
{
	workers_.push_back(&e);
}

void Personnel::removeWorker(std::string name)
{
	for (List<Employee*>::iterator it = workers_.begin(); it != workers_.end(); it++)
	{
		Employee* e = *it;
		if (e->getName().compare(name) == 0)
		{
			workers_.erase(it);
			break;
		}
	}
}

int Personnel::calculateMonthlyCosts()
{
	int sum = 0;

	for (List<Employee*>::iterator it = workers_.begin(); it != workers_.end(); it++)
	{
		sum += (*it)->getSalary();
	}

	return sum;
}

void Personnel::printWorkers()
{
	for (List<Employee*>::iterator it = workers_.begin(); it != workers_.end(); it++)
	{
		(*it)->printInfo();
		std::cout << std::endl;
	}
}

Employee& Personnel::operator[](int index)
{
	return *workers_[index];
}

int Personnel::size()
{
	return workers_.size();
}