#include <iostream>
#define MIN_N 10
#define MAX_N 20

using namespace std;

void countDigits(int arr[], int count[], int size) {
	int x;
	for (int i = 0; i < size; ++i) {
		x = arr[i];
		while (x > 0) {
			++count[x % 10];
			x /= 10;
		}
	}
}

int main() {
	int num[MAX_N];

	int n;
	cin >> n;
	while (n < MIN_N || n > MAX_N) {
		cout << "Wrong value for n[" << MIN_N << ";" << MAX_N << "]" << endl;
		cin >> n;
	}

	for (int i = 0; i < n; ++i) cin >> num[i];

	int count[10] = {};
	countDigits(num, count, n);

	int max = 0;
	for (int i = 0; i < 10; ++i) {
		if (count[max] < count[i])
			max = i;
	}
	cout << "Most frequent digit is " << max << endl;

	cout << "Numbers with even number of digits" << endl;
	for (int i = n - 1; i >= 0; --i) {
		int numDigits = floor(log10(num[i]) + 1);
		if (numDigits % 2 == 0)
			cout << num[i] << endl;
	}

	return 0;
}