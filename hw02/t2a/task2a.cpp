#include <iostream>
#define MAX_N 1000

using namespace std;

int main() {
	int num[MAX_N];

	int n = 0;
	do {
		cin >> num[n];
	} while (num[n++] > 0 && n < MAX_N);

	int max = 0;
	for (int i = 0; i < n; ++i) {
		if (num[i] % 2 != 0 && num[i] > max) {
			max = num[i];
		}
	}

	if (max == 0) {
		cout << "These are only even numbers" << endl;
	}
	else {
		cout << "Biggest odd number is " << max << endl;
	}

	return 0;
}