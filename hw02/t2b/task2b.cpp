#include <iostream>
#define MIN_N 1
#define MAX_N 1000

using namespace std;

int main() {
	int num[MAX_N];
	
	int n;
	cin >> n;
	while (n < MIN_N || n > MAX_N) {
		cout << "Wrong value for n[" << MIN_N << ";" << MAX_N << "]" << endl;
		cin >> n;
	}

	for (int i = 0; i < n; ++i) cin >> num[i];

	for (int i = 0; i < n; ++i) {
		if (num[i] == num[i + 1]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

	return 0;
}