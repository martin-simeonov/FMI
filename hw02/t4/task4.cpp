#include <iostream>
#define MIN_N 10
#define MAX_N 20

using namespace std;

void sortArray(int arr[], int size) {
	int min;
	for (int i = 0; i < size; ++i) {
		min = i;

		for (int j = i + 1; j < size; ++j) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}

		if (min != i) {
			swap(arr[i], arr[min]);
		}
	}
}

int main() {
	int a[MAX_N];

	int n;
	cin >> n;
	while (n < MIN_N || n > MAX_N) {
		cout << "Wrong value for n[" << MIN_N << ";" << MAX_N << "]" << endl;
		cin >> n;
	}

	for (int i = 0; i < n; ++i) cin >> a[i];

	int size = (n % 2 == 0) ? n / 2 : (n - 1) / 2;

	int first[MAX_N/2];
	int second[MAX_N/2];
	int result[MAX_N];

	int k;

	// Divide the array into two parts
	for (int i = 0; i < size; ++i) {
		first[i] = a[i];
	}
	for (int i = n - 1, k = 0; i >= size; --i, ++k) {
		second[k] = a[i];
	}

	sortArray(first, size);
	sortArray(second, size);

	// Insert the arrays in result
	for (int i = 0; i < size; ++i) {
		result[i] = first[i];
	}
	for (int i = size, k = 0; i < size * 2; ++i, ++k) {
		result[i] = second[k];
	}

	cout << "Result:" << endl;
	for (int i = 0; i < size * 2; ++i) {
		cout << result[i] << endl;
	}

	return 0;
}