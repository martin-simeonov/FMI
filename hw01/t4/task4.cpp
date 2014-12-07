#include <iostream>

using namespace std;

int main() {
	cout << "Enter number:";

	unsigned n;
	cin >> n;

	if (n < 111 || n > 999) {
		cout << "wrong value" << endl;
		return -1;
	}

	bool fact = true;
	int sum = 0;
	int prod = 1;
	unsigned x = n;

	while (x > 0) {
		int digit = x % 10;

		if (digit != 0) {
			sum += digit;
			prod *= digit;

			if (n % digit != 0) fact = false;
		}
		else {
			cout << "wrong value" << endl;
			return -1;
		}
		x /= 10;
	}

	if (fact) {
		cout << "Yes" << endl;
		cout << "sum = " << sum << endl;
	}
	else {
		cout << "No" << endl;
		cout << "prod = " << prod << endl;
	}

	return 0;
}