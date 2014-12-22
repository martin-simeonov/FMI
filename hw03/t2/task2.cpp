#include <iostream>
#define MIN_N 1
#define MAX_N 20

using namespace std;

int main() {
	int matrix[MAX_N][MAX_N];

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

	int rowSum = 0;
	int colSum = 0;

	for (int j = 0; j < n; ++j) rowSum += matrix[0][j];
	for (int i = 0; i < n; ++i) colSum += matrix[i][0];

	if (rowSum != colSum) {
		cout << "not magic" << endl;
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		int row = 0, col = 0;

		for (int j = 0; j < n; ++j) {
			row += matrix[i][j];
			col += matrix[j][i];
		}
		if (rowSum != row || rowSum != col) {
			cout << "not magic" << endl;
			return 0;
		}
	}

	cout << "yes it's magic" << endl;

	return 0;
}