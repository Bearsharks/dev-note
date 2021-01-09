#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			v[i][j] = c- '0';
		}
	}
	vector<int> sums(m);
	vector<int> d(m);

	for (int i = 0; i < n; i++) {
		int init = 0;
		for (; init < m; init++) {
			if (v[i][init] == 1) break;
		}
		if (init == m) {
			cout << -1;
			return 0;
		}
		int cnt = 1;
		int index = 0;
		for (int j = init+1; (index = j % m) != init; j++) {
			if (v[i][index] == 1) {
				cnt = 0;
			}
			d[index] = cnt++;
		}
		cnt = 1;
		for (int j = init + m - 1; (index = j % m) != init; j--) {
			if (v[i][index] == 1) {
				cnt = 0;
			}
			sums[index] += min(cnt++, d[index]);
		}
	}

	int ans = INT_MAX;
	for (int i : sums) {
		ans = min(ans, i);
	}
	cout << ans;
	return 0;
}