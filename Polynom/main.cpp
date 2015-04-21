#include "Polynom.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<double> a = {1, 0,-3,0,123};
	Polynom p1(a);
	vector<double> b = { 2, 3, -5, 4, 23 };
	Polynom p2(b);

	cout << p1(5) << endl;

	return 0;
}