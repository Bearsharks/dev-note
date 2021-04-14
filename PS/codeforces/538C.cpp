#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<pair<int, int>> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i].first >> v[i].second;
	}
	int mx = max(v[0].first - 1  + v[0].second , n - v[m-1].first  + v[m-1].second);
	for (int i = 1; i < m; i++) {
		int need = abs(v[i].second - v[i - 1].second);
		int day = abs(v[i].first - v[i - 1].first);		
		if (day < need) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		int remain = max(day - need - 1, 0);
		int cur = max(v[i].second, v[i - 1].second) + remain / 2 + (remain & 1);
		mx = max(mx, cur);
	}
	cout << mx;
	return 0;
}