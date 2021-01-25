#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		int d, x;
		cin >> d >> x;
		v.push_back({ d, x });
		if (d == 1) q.push(i);
	}
	vector<pair<int, int>> ans;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (v[cur].first == 0) continue;
		ans.push_back({ cur,v[cur].second });
		int next = v[cur].second;
		v[next].first--;
		v[next].second = v[next].second ^ cur;
		if (v[next].first == 1) q.push(next);
	}

	cout << ans.size() << "\n";
	for (pair<int, int> p : ans) {
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}