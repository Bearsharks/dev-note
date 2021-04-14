#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	
	int n = t.size();
	int m = s.size();
	vector<int> v(n+1);
	vector<int> save(m+1);

	for (int i = 1; i <= n; i++) {
		v[i] = t[i-1] - '0';
		v[i] += v[i - 1];
	}

	int cur = 1;
	for (int i = n-m+1; i <= n; i++) {
		save[cur] = v[i] - v[cur-1];
		cur++;
	}
	long long ans = 0;
	int cnt = n - m + 1;
	for (int i = 1; i <= m; i++) {
		if (s[i - 1] == '0') {
			ans += save[i];
		}
		else {
			ans += cnt - save[i];
		}
	}
	cout << ans;
	return 0;
}