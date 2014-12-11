#include <iostream>

using namespace std;

bool isCorrect(char field[]) {
	field[0] = tolower(field[0]);
	return field[0] >= 'a' && field[0] <= 'h' && field[1] >= '1' && field[1] <= '8';
}

int main() {
	char firstField[2];
	char secondField[2];

	do {
		cout << "Enter first field x[a-h], y[1-8]: ";
		cin >> firstField[0] >> firstField[1];
		cout << "Enter second field x[a-h], y[1-8]: ";
		cin >> secondField[0] >> secondField[1];
	} while (!isCorrect(firstField) || !isCorrect(secondField));

	if (firstField[0] == secondField[0] || firstField[1] == secondField[1]) {
		cout << "Yes, you can go with one turn from "
			<< firstField[0] << firstField[1] << " to "
			<< secondField[0] << secondField[1] << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}