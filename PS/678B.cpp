#include <iostream>
using namespace std;

bool is366(int year) {
	return year % 400 == 0 || (year % 4 == 0 && (year % 100) != 0);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int y;
	cin >> y;
	int ans = y;
	int cur = 1;
	int days[2] = { 365, 366 };
	do {
		int test = is366(ans);
		cur = cur + days[is366(ans++)];
		cur = (cur) % 7;
	} while (cur != 1 || is366(ans) != is366(y));
	cout << ans;
	return 0;
}