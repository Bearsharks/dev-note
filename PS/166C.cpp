#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int ng = 0, ns = 0, nm = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		if (a > m) {
			ng++;
		}
		else if (a < m) {
			ns++;
		}
		else {
			nm++;
		}
	}
	int ans = 0;
	if (ng > ns) {
		ans = ng - ns - nm;
	}
	else {
		ans = ns - ng - nm + 1;
	}
	ans = max(ans, 0);
	cout << ans;
	return 0;
}