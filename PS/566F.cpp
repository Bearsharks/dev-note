#include <iostream>
#include <vector>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(1000001);
	int mx = -1;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v[a] = 1;
		mx = (max(a, mx));
	}

	int ans = 0;
	for (int i = 1; i <= mx; i++) {
		if (v[i]) {
			int cur = i+i;
			int cnt = v[i];
			while (cur <= mx) {
				if (v[cur]) {
					v[cur] = max(cnt+1, v[cur]);
				}
				cur += i;
			}
			ans = max(ans, v[i]);
		}
	}
	cout << ans;
	return 0;
}