#include <iostream>
#include <vector>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int size = s.size();
	vector<vector<int>> v(3, vector<int>(size+1));
	vector<int> cnt(3);
	for (int i = 0; i < size; i++) {
		cnt[s[i] - 'x']++;
		v[0][i + 1] = cnt[0];
		v[1][i + 1] = cnt[1];
		v[2][i + 1] = cnt[2];
	}

	int m;
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		if (r - l + 1 < 3) {
			cout << "YES\n";
			continue;
		}
		int mn = INT_MAX, mx = -1;
		for (int i = 0; i < 3; i++) {
			mn = min(v[i][r] - v[i][l - 1], mn);
			mx = max(v[i][r] - v[i][l - 1], mx);
		}
		if (mx - mn <= 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
