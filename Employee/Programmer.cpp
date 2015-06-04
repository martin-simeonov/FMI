#include "Programmer.h"

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
}

Programmer& Programmer::setCsharp(bool csharp)
{
	csharp_ = csharp;
}