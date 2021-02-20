#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a[6];
	int i = 0;
	while (i<6) {
		cin >> a[i++];

	}
	int ans = 0;

		int mn = min(a[1], a[5]);
		int l0 = a[0];
		int l1 = a[0] + mn;
		int side = abs(a[1] - a[5]);
		ans += side * l1 * 2;
		ans += (l1 - l0 - 1) * (l0 + l1) + l0 + l1;
		int fl = a[3];
		ans += (l1 - fl - 1) * (fl + l1) + fl + l1;

		cout << ans;
	return 0;
}