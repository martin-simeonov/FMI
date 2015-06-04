#include "Employee.h"

Employee::Employee(std::string name, int service, int salary)
: name_(name), service_(service), salary_(salary)
{}

std::string Employee::getName() const
{
	return name_;
}

int Employee::getService() const
{
	return service_;
}

int Employee::getSalary() const
{
	return salary_;
}

Employee& Employee::setService(int service)
{
	service_ = service;
}

Employee& Employee::setSalary(int salary)
{
	salary_ = salary;
}