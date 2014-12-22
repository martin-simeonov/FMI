#include <iostream>
#define MIN_N 3
#define MAX_N 20

using namespace std;

int main() {
	double matrix[MAX_N][MAX_N];
	
	int n;
	cin >> n;
	while (n < MIN_N || n > MAX_N) {
		cout << "Wrong value for n[" << MIN_N << ";" << MAX_N << "]" << endl;
		cin >> n;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << "enter element " << i + 1 << "," << j + 1 << ": ";
			cin >> matrix[i][j];
		}
	}

	double upperSum = 0, lowerSum = 0;
	int middle = n / 2;

	for (int i = 0; i < middle; ++i) {
		for (int j = i + 1; j < (n - (i + 1)); ++j)
			upperSum += matrix[i][j];
	}
	for (int i = n - 1; i > middle; --i) {
		for (int j = i - 1; j > (n - (i + 1)); --j)
			lowerSum += matrix[i][j];
	}
	cout << "A) upper sum = " << upperSum << ", lower sum = " << lowerSum << endl;

	double diagSum = 0;

	for (int i = 0, j = 1; i < n - 1; ++i, ++j) diagSum += matrix[i][j];
	cout << "B) diag above main sum = " << diagSum << endl;
	
	double diagProd = 1;

	for (int i = 1, j = n - 1; i < n; ++i, --j) diagProd *= matrix[i][j];
	cout << "C) diag below secondary product = " << diagProd << endl;

	return 0;
}