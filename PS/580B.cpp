#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,d;
	cin >> n>>d;
	vector<pair<int,int>> v(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = { a, b };
	}
	sort(v.begin(), v.end());
	int mn = 0;
	long long cur = v[0].second;
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		if (v[i].first - v[mn].first >= d) {
			ans = max(ans, cur);
			do {
				cur -= v[mn].second;
				mn++;
			} while (v[i].first - v[mn].first >= d);
		}
		cur += v[i].second;
	}
	ans = max(ans, cur);
	cout << ans;
	return 0;
}