#ifndef _PROGRAMMER_H
#define _PROGRAMMER_H

#include "Employee.h"

class Programmer : public Employee
{
	bool cplus_;
	bool csharp_;
public:
	Programmer(std::string, int, int, bool, bool);
	Programmer(std::string, int, int);

	bool getCplus() const;
	bool getCsharp() const;
	Programmer& setCplus(bool);
	Programmer& setCsharp(bool);

	void printInfo();
};

#endif