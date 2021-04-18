#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<long long, long long>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	long long answer = 0;

	long long a = v[0].first, b = v[0].second;
	long long c = v[1].first, d = v[1].second;
	for (int i = 2; i < n; i++) {
		long long e = v[i].first;
		long long f = v[i].second;
		answer += (c - a) * (f - b) - (d - b) * (e - a);
		c = e, d = f;
	}
	answer = abs(answer);
	cout << answer/2 << '.';
	if (answer % 2 == 0) cout << 0;
	else cout << 5;
	
	return 0;
}