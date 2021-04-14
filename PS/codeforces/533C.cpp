#include <iostream>

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int x1, y1, x2, y2;
	cin >> x1>> y1>> x2>> y2;
	if (x1 >= x2 && y1 >= y2) {
		cout << "Vasiliy";
	}
	else if (x1 <= x2 && y1 <= y2) {
		cout << "Polycarp";
	}
	else if (x1 > x2 && y1 < y2) {
		x2 = max(x2 - (y2 - y1), 0);
		if(y2-y1 >= x1 - x2)cout << "Polycarp"; 
		else cout << "Vasiliy";
	}
	else {
		y2 = max(y2 - (x2 - x1), 0);
		if (x2 - x1 >= y1 - y2)cout << "Polycarp";
		else cout << "Vasiliy";
	}
	return 0;
}
