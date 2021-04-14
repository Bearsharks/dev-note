#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	ull n;
	cin >> n;
	vector<pair<ull, ull>> v(n);

	ull maxmax = 0;
	for (int i = 0; i < n; i++) {
		ull m,a;
		cin >> m;
		ull mx = 0;
		for (int j = 0; j < m; j++) {
			cin >> a;
			mx = max(a, mx);
		}
		maxmax = max(mx, maxmax);
		v[i] = { mx, m };
	}
	unsigned long long ans = 0;
	for (pair<ull, ull> p:v) {
		ans += (maxmax - p.first) * p.second;
	}
	cout << ans;
	return 0;

}
