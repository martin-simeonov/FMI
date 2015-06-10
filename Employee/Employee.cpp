#include "Employee.h"
#include <iostream>

Employee::Employee(std::string name, int service, int salary)
: name_(name), service_(service), salary_(salary)
{}

Employee::Employee()
: name_(""), service_(0), salary_(0)
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
	return *this;
}

Employee& Employee::setSalary(int salary)
{
	salary_ = salary;
	return *this;
}

void Employee::printInfo()
{
	std::cout << "Name: " << name_ << ", ";
	std::cout << "Service: " << service_ << " months, ";
	std::cout << "Salary: " << salary_;
}