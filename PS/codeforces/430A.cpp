#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<pair<int, int>> v(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		ans[v[i].second] = i & 1;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}