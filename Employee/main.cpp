#include "List.cpp"
#include "Manager.h"
#include "Programmer.h"
#include "Personnel.h"
#include <iostream>
using namespace std;

int main()
{
	Programmer p1("Marto", 5, 1500, true, true);
	Programmer p2("Pesho", 3, 800, true, false);
	Programmer p3("Ivo", 2, 200, false, false);
	Employee e1("Gosho", 1, 400);
	Manager m1("Ivan", 24, 2300);
	m1.addWorker(p1);
	m1.addWorker(p2);
	m1.addWorker(e1);

	Employee e2("Dobri", 12, 200);

	Personnel personnel;
	personnel.addWorker(p1);
	personnel.addWorker(p2);
	personnel.addWorker(p3);
	personnel.addWorker(e1);
	personnel.addWorker(m1);
	personnel.addWorker(e2);

	for (int i = 0; i < personnel.size(); ++i)
	{
		Programmer* p = dynamic_cast<Programmer*> (&personnel[i]);
		if (p != NULL)
		{
			if (p->getCplus())
				p->setSalary(p->getSalary() + 500);
		}
	}
	
	for (int i = 0; i < personnel.size(); ++i)
	{
		Programmer* p = dynamic_cast<Programmer*> (&personnel[i]);
		if (p != NULL)
		{
			if (!(p->getCplus()) && !(p->getCsharp()))
				personnel.removeWorker(p->getName());
		}
	}

	personnel.printWorkers();
	cout << "Costs: " << personnel.calculateMonthlyCosts() << endl;
	
	return 0;
}