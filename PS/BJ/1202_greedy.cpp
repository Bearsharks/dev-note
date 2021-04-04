#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n>>m;
	vector<pair<int,int>> j(n);
	vector<int> bag(m);
	for (int i = 0; i < n; i++) {
		cin >> j[i].first >> j[i].second;
	}
	for (int i = 0; i < m; i++) {
		cin >> bag[i];
	}
	sort(j.begin(), j.end());
	sort(bag.begin(), bag.end());
	long long ans = 0;
	priority_queue<int> q;
	vector<pair<int, int>>::iterator prev = j.begin();
	for (int i : bag) {
		vector<pair<int, int>>::iterator cur = upper_bound(prev,j.end(),make_pair(i+1,-1));
		while (prev != cur) {
			q.push(prev->second);
			prev++;
		}
		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}		
	}
	cout << ans;
	return 0;
}