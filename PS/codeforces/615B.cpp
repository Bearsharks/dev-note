#include <iostream>
#include <vector>	
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n+1);
	vector<int> dp(n+1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = 1;
		for (int ne : v[i]) {
			if (i > ne) {
				dp[i] = max(dp[i], dp[ne] + 1);
			}			
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(dp[i]*(long long)v[i].size(),ans);
	}
	cout << ans;
	return 0;
}