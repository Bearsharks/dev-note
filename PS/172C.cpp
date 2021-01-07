#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool test(pair<int,int>& a, pair<int, int>& b) {
	return a.second < b.second;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v(n + 1);
	vector<pair<int, int>> ans;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}

	int t = 0;
	for (int i = 1; i <= n; i++) {
		int last = min(i + m - 1, n);
		t = max(v[last].first, t);
		sort(v.begin() + i, v.begin() + last+1, test);
		int prev = 0;
		while ( i <= last) {
			t += v[i].second - prev;
			prev = v[i].second;
			int cnt = 0;
			while (i <= last && v[i].second == prev) {
				ans.push_back({ v[i].first, t });
				i++;
				cnt++;				
			} 
			t += 1 + cnt / 2;
		}
		t += v[last].second;
	}
	sort(ans.begin(), ans.end());
	for (pair<int, int> p : ans) {
		cout << p.second << " ";
	}
	return 0;
}