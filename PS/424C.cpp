#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n+1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		ans = ans ^ v[i];
	}
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		dp[i] = (i-1) ^ dp[i - 1];
	}
	for (int i = 2; i <= n; i++) {
		int div = n / i;
		int mod = n % i;
		if ((div & 1) == 1) {
			ans = ans ^ dp[i] ^ dp[mod+1];
		}
		else {
			ans = ans ^ dp[mod + 1];
		}
	}
	cout << ans;
	return 0;
}