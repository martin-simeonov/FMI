#include "Polynom.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	Polynom p1;
	p1.setCoef(12, 3);
	p1.setDegree(7, 3);
	p1[6] = 9;

	double v1[] = { 12, 0, 0, 3, 12, 2, 2, -5, -12, 2 };
	vector<double> vv(begin(v1), end(v1));
	Polynom p2(vv, 5);

	cout << "Poly1:" << endl << p1 << endl;
	cout << "Poly2:" << endl << p2 << endl;

	cout << "Poly1 + Poly2:" << endl << p1 + p2 << endl;

	p1 *= p2;
	cout << "Poly1 *= p2:" << endl << p1 << endl;

	p2 *= 3;
	cout << "Poly2 *= 3:" << endl << p2 << endl;

	cout << "Poly2 value at x=-6: " << p2(-6) << endl;

	cout << "Poly1 differential:" << endl << --p1 << endl;

	p1++;
	cout << "Poly1 integral:" << endl << p1 << endl;

	return 0;
}