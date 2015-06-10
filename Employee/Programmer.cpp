#include "Programmer.h"
#include <iostream>

Programmer::Programmer(std::string name, int service, int salary, 
					   bool cplus, bool csharp)
: Employee(name, service, salary), cplus_(cplus), csharp_(csharp)
{}

Programmer::Programmer(std::string name, int service, int salary)
: Employee(name, service, salary)
{}

bool Programmer::getCplus() const
{
	return cplus_;
}

bool Programmer::getCsharp() const
{
	return csharp_;
}

Programmer& Programmer::setCplus(bool cplus)
{
	cplus_ = cplus;
	return *this;
}

Programmer& Programmer::setCsharp(bool csharp)
{
	csharp_ = csharp;
	return *this;
}

void Programmer::printInfo()
{
	Employee::printInfo();

	if (cplus_)
		std::cout << ", Knows C++";
	if (csharp_)
		std::cout << ", Knows C#";
}