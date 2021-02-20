#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> m(n+2);
	set<pair<int,int>> s;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
		s.insert({m[i], i});
	}
	int ans = 0;
	while (!s.empty()) {		
		int h = s.begin()->first;
		int v = s.begin()->second;
		s.erase(s.begin());

		int l = min(min(h, min(n - v + 1, v)),m[v]);
		m[v] = l;
		ans = max(l, ans);
		int nextval = min(l + 1, m[v + 1]);
		if (s.count({ m[v + 1], v + 1 })) {
			s.erase({ m[v + 1], v + 1 });
			s.insert({ nextval, v + 1 });			
		}
		m[v + 1] = nextval;
		int prevval = min(l + 1, m[v - 1]);
		if (s.count({ m[v - 1], v - 1 })) {
			s.erase({ m[v - 1], v - 1 });
			s.insert({ prevval, v - 1 });			
		}
		m[v - 1] = prevval;
	}
	cout << ans;
	return 0;
}