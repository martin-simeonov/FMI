#include <iostream>

using namespace std;

int main() {
	cout << "Enter number:";
	unsigned n;
	cin >> n;

	unsigned digits[3];

	if (n < 0 && n > 1000) {
		cout << "wrong value" << endl;
		return -1;
	}

	if (n == 1000) {
		cout << "hilqda" << endl;
		return 0;
	}

	for (int i = 0; n > 0; i++) {
		digits[i] = n % 10;
		n /= 10;
	}

	bool hundreds = true;
	bool tenths = true;

	switch (digits[2]) {
	case 1: cout << "sto "; break;
	case 2: cout << "dvesta "; break;
	case 3: cout << "trista "; break;
	case 4: cout << "chetiristotin "; break;
	case 5: cout << "petstotin "; break;
	case 6: cout << "sheststotin "; break;
	case 7: cout << "sedemstotin "; break;
	case 8: cout << "osemstotin "; break;
	case 9: cout << "devetstotin "; break;
	default: hundreds = false;
	}

	if (hundreds && (digits[0] == 0 || digits[1] == 1)) cout << "i ";

	switch (digits[1]) {
	case 1:
		switch (digits[0]) {
		case 0: cout << "deset" << endl; return 0;
		case 1: cout << "edinadeset" << endl; return 0;
		case 2: cout << "dvanadeset" << endl; return 0;
		case 3: cout << "trinadeset" << endl; return 0;
		case 4: cout << "chetirinadeset" << endl; return 0;
		case 5: cout << "petnadeset" << endl; return 0;
		case 6: cout << "shestnadeset" << endl; return 0;
		case 7: cout << "sedemnadeset" << endl; return 0;
		case 8: cout << "osemnadeset" << endl; return 0;
		case 9: cout << "devetnadeset" << endl; return 0;
		}
		break;
	case 2: cout << "dvadeset "; break;
	case 3: cout << "trideset "; break;
	case 4: cout << "chetirideset "; break;
	case 5: cout << "petdeset "; break;
	case 6: cout << "shestdeset "; break;
	case 7: cout << "sedemdeset "; break;
	case 8: cout << "osemdeset "; break;
	case 9: cout << "devetdeset "; break;
	default: tenths = false;
	}

	if ((hundreds || tenths) && digits[0] != 0) cout << "i ";

	switch (digits[0]) {
	case 1: cout << "edno"; break;
	case 2: cout << "dve"; break;
	case 3: cout << "tri"; break;
	case 4: cout << "chetiri"; break;
	case 5: cout << "pet"; break;
	case 6: cout << "shest"; break;
	case 7: cout << "sedem"; break;
	case 8: cout << "osem"; break;
	case 9: cout << "devet"; break;
	}

	cout << endl;

	return 0;
}