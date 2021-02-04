#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	c1--; c2--;	

	int low = r1 > r2 ? r2 : r1;
	int high = r1 > r2 ? r1 : r2;
	int mn = c1;
	
	for (int i = low; i <= high; i++) {
		mn = min(mn, v[i]);
	}
	int ans = abs(c2 - mn) + abs(r1 - r2);
	int lowmn = mn;
	for (int i = low - 1; i > 0; i--) {
		lowmn = min(lowmn, v[i]);
		ans = min(ans, abs(c2 - lowmn) + abs(r2 - i) + abs(r1 - i));
	}
	for (int i = high + 1; i <= n; i++) {
		mn = min(mn, v[i]);
		ans = min(ans, abs(c2 - mn) + abs(r2 - i) + abs(r1 - i));
	}
	cout << ans;

	return 0;
}