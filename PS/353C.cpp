#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	int total = 0;
	int sum0 = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		total += v[i];
	}
	string s;
	cin >> s;
	for (int i = 0; i < n;i++) {
		if (s[i] == '0') sum0 += v[i];
	}
	int save = 0;
	int ans = total - sum0;
	int mn = INT_MAX;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == '0') {
			ans = max(ans, save + total - mn);
			sum0 -= v[i];
			total -= v[i];
		}
		else {
			mn = min(v[i], mn);
			save += v[i];
			total -= v[i];
		}
	}
	cout << ans;
	return 0;
}