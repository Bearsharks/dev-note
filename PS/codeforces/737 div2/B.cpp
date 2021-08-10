#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].first;
			v[i].second = i;
		}
		sort(v.begin(), v.end());
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (v[i - 1].second + 1 != v[i].second) {
				cnt++;
			}
		}
		if (cnt <= k) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}