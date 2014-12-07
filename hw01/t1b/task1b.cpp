#include <iostream>
#include <string>

using namespace std;

int main() {
	float x, y;

	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;

	float cx = 4;
	float cy = -2;
	float r;
	string where = "outside";

	if (x >= 0 && x <= 8 && y >= -6 && y <= 0) {
		float arc = (x - cx)*(x - cx) + (y - cy)*(y - cy);

		if (y <= -2) {
			r = 4;
			where = (arc <= (r*r)) ? "inside" : "outside";
		}
		else {
			r = 2;
			bool con1 = arc <= r*r;
			r = 1;
			bool con2 = arc >= r*r;
			where = (con1 && con2) ? "inside" : "outside";
		}
	}
	cout << where << endl;

	return 0;
}