#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> v(n);
	vector<int> alpha(26);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		reverse(v[i].begin(), v[i].end());
		for (int j = 0, d = 1; j < v[i].size(); j++, d*=10) {
			alpha[v[i][j] - 'A'] += d;
		}
	}
	sort(alpha.begin(),alpha.end(),greater<int>());
	long long ans = 0;
	long long cur = 9;
	for (int i = 0; i < 9; i++) {
		ans += alpha[i] * cur--;
	}
	cout << ans;
	return 0;
}