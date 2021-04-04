#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> j(n);
	multiset<int> bag;
	for (int i = 0; i < n; i++) {
		cin >> j[i].second >> j[i].first;
	}
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		bag.insert(a);
	}
	sort(j.begin(), j.end(),greater<pair<int,int>>());

	long long ans = 0;
	for (pair<int,int> i : j) {
		multiset<int>::iterator cur = bag.lower_bound(i.second);
		if (cur != bag.end()) {
			ans += i.first;
			bag.erase(cur);
		}
	}
	cout << ans;
	return 0;
}