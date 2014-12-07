#include <iostream>

using namespace std;

int main() {
	int a, b;

	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;

	bool state = (a % 2013 == 0) ^ (b % 2013 == 0);

	cout << state << endl;

	return 0;
}