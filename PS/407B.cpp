#include <iostream>
#include <vector>
using namespace std;

int d = 1e9 + 7;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	vector<int> dp(n + 1);
	for (int i = 1; i <=n; i++) {
		dp[i] = (dp[i - 1] + (dp[i - 1] - dp[v[i] - 1]) + 2) % d;
		if (dp[i] < 0) dp[i] += d;
	}
	cout << dp.back();
	return 0;
}