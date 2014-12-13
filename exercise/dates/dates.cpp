#include <iostream>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

Date createDate(int day, int month, int year) {
	Date date;
	date.day = day;
	date.month = month;
	date.year = year;
	return date;
}

Date inputDate() {
	Date date;
	cin >> date.day >> date.month >> date.year;
	return date;
}

ostream& operator<<(ostream& out, Date date) {
	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}

void printDate(Date date) {
	cout << date << endl;
}

int dayNumber(int y, int m, int d) {
	m = (m + 9) % 12;
	y = y - m / 10;
	return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);
}

bool operator<(Date left, Date right) {
	int dNumLeft = dayNumber(left.year, left.month, left.day);
	int dNumRight = dayNumber(right.year, right.month, right.day);

	if (dNumLeft < dNumRight) {
		return true;
	}
	return false;
}

bool isDateSmaller(Date left, Date right) {
	return left < right;
}

bool isLeapYear(int year) {
	bool fourFactor = year % 4 == 0;
	bool hundredFactor = year % 100 == 0;
	bool fhundredFactor = year % 400 == 0;

	return fourFactor && (!hundredFactor || fhundredFactor);
}

Date nextDate(Date date) {
	Date next = date;

	switch (next.month) {
	case 4: case 6: case 9: case 11:
		if (next.day == 30) {
			++next.month; next.day = 1;
			break;
		}
	case 1:case 3:case 5: case 7: case 8: case 10:
		if (next.day == 31) {
			++next.month; next.day = 1;
			break;
		}
	case 2:
		if ((isLeapYear(next.year) && next.day == 29) ||
			(!isLeapYear(next.year) && next.day == 28)) {
			++next.month; next.day = 1;
			break;
		}
	case 12:
		if (next.day == 31) {
			++next.year; next.month = 1; next.day = 1;
			break;
		}
	default: ++next.day;
	}
	return next;
}

Date operator+(Date date, int n) {
	Date after = date;
	for (int i = 0; i < n; ++i) {
		after = nextDate(after);
	}
	return after;
}

Date theDateAfterNdays(Date date, int n) {
	return date + n;
}

void sortDates(Date dates[], int left, int right) {
	if (left < right) {
		int pIndex = (left + right) / 2;
		Date pValue = dates[pIndex];

		swap(dates[pIndex], dates[right]);
		int storeIndex = left;

		for (int i = left; i < right; ++i) {
			if (dates[i] < pValue) {
				swap(dates[i], dates[storeIndex]);
				++storeIndex;
			}
		}
		swap(dates[storeIndex], dates[right]);

		sortDates(dates, left, storeIndex - 1);
		sortDates(dates, storeIndex + 1, right);
	}
}

int main() {
	Date arr[4] = { 14, 12, 2014, 12, 1, 2013, 4, 5, 2006, 3, 8, 2015 };
	sortDates(arr, 0, 3);

	for (int i = 0; i < 4; ++i) {
		cout << arr[i] << endl;
	}
}