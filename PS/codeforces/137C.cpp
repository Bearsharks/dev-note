#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	
	sort(v.begin(), v.end());

	pair<int, int> cur = v[0];
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (cur.second > v[i].second) ans++;
		else cur = v[i];
	}
	cout << ans;
	return 0;
}