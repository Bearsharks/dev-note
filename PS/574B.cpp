#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> isvisit(4001);
vector<unordered_set<int>> v(4001);
vector<int> cnt(4001);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >>m;
	
	for (int i = 1; i <=m ; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		cnt[a]++; cnt[b]++;
		v[a].insert(b);
	}
	int ans = INT_MAX;
	for (int i = 1; i < n-1; i++) {
		int size = v[i].size();
		for (unordered_set<int>::iterator j = v[i].begin(); j != v[i].end(); j++) {
			unordered_set<int>::iterator next = j;
			next++;
			for (unordered_set<int>::iterator k = next; k != v[i].end(); k++) {
				if (v[*j].count(*k)) {
					ans = min(ans, cnt[i] + cnt[*j] + cnt[*k] - 6);
				}
			}
		}
	}
	if (ans == INT_MAX) ans = -1;
	cout << ans;
	return 0;
}