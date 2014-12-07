#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cout << "Enter number:";

	unsigned n;
	cin >> n;

	if (n < 0) {
		cout << "wrong value" << endl;
		return -1;
	}

	unsigned newN = 0;
	unsigned x = n;
	unsigned tenths = pow(10, floor(log10(n) + 1));

	while (x > 0) {
		tenths /= 10;
		newN += (x % 10) * tenths;
		x /= 10;
	}

	if (n == newN) {
		cout << "is palindrome" << endl;
	}
	else {
		cout << "not a palindrome" << endl;
	}

	return 0;
}