#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
long long d = 1000000007;
int n, k;
int f(int cur) {
	if (cur < 0) return 0;
	int& ret = dp[cur];
	if (ret != -1) return ret;
	int newW = (d + f(cur - k) - f(cur - k - 1)) % d;
	if (newW == 0) ++newW;
	return ret = (d + 2 * f(cur - 1) - f(cur - 2) + newW) % d;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	dp.assign(100001, -1);
	for (int i = 0; i < k; i++) {
		dp[i] = i;
	}
	if (k == 1) {
		dp[1] = 2;
	}

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cout << (d + f(b) - f(a - 1)) % d << "\n";
	}
	return 0;
}