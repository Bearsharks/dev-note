#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a;
	cin >> a;
	string s;
	cin >> s;
	vector<int> v(4001);
	v[1] = s[0] - '0';
	int n = s.size();
	for (int i = 2; i <= n; i++) {
		v[i] += s[i-1] - '0' + v[i-1];
	}
	unordered_map<int, int> m;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			m[v[j] - v[i - 1]]++;
		}
	}
	long long ans = 0;
	if (a == 0) {
		cout << ((long long) n * (n + 1) - m[0]) * m[0];
		return 0;
	}
	m.erase(0);
	for (pair<int,int> p:m) {
		if (a % p.first == 0 && m.count(a / p.first)) {
			ans += (long long)p.second * m[a / p.first];
		}
	}
	cout << ans;
	return 0;
}