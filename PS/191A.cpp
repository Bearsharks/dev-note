#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int dp[27][27] = { 0, };
	while (n--) {
		string cur;
		cin >> cur;
		int next = 0;		
		int size = cur.size();
		for (int i = 0; i < 27; i++) {
			if (dp[i][cur[0] - 'a']) {
				dp[i][cur.back() - 'a'] = max(dp[i][cur.back() - 'a'], dp[i][cur[0] - 'a'] + size);
			}
		}
		dp[cur[0] - 'a'][cur.back() - 'a'] = max(dp[cur[0] - 'a'][cur.back() - 'a'], size);
		
	}
	int ans = 0;

	for (int i = 0; i < 27; i++) {
		ans = max(dp[i][i], ans);
	}
	cout << ans;
	return 0;
}