#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	vector<int> v(n + 1);
	v[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	long long cnt = 0;
	for (int i = n; i > 0; i--) {
		if (v[i] <= v[i - 1]) {
			int next = max(v[i] - 1, 1);
			cnt = cnt + v[i - 1] - next;
			v[i - 1] = next;
		}
		cnt += (v[i] == 1) ? 0 : v[i - 1];
	}
	cout << cnt;
	return 0;
}