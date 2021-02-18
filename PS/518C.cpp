#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> curpos(n + 1);
	vector<int> list(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> list[i];
		curpos[list[i]] = i;
	}
	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		int cur;
		cin >> cur;
		int pos = curpos[cur];
		if (pos > 1) {
			int prev = list[pos - 1];
			swap(list[pos - 1], list[pos]);
			curpos[cur]--;
			curpos[prev]++;
		}
		ans += pos / k + !!(pos % k);
	}
	cout << ans;
	return 0;
}