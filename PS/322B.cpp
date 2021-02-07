#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int r, g, b;
	cin >> r >> g >> b;

	int ans = r / 3 + g / 3 + b / 3;
	if (r > 0 && g > 0 && b > 0) {
		ans = max(ans,(r - 1) / 3 + (g - 1) / 3 + (b - 1) / 3 + 1);
	}
	if (r > 1 && g > 1 && b > 1) {
		ans = max(ans, (r - 2) / 3 + (g - 2) / 3 + (b - 2) / 3 + 2);
	}
	cout << ans;
	return 0;
}