#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	long long ans = 0;
	long long each = sum / n;
	long long cur = 0;
	for (int i = 0; i < n; i++) {
		cur += each - v[i];
		ans += abs(cur);
	}
	cout << ans;
	return 0;
}