#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	int ans = n;
	for (int i = 0; i < n; i++) {
		int edge = v[i].first - v[i].second;
		vector<pair<int, int>>::iterator lmd = upper_bound(v.begin(),v.end(), make_pair(edge - 1, INT_MAX));
		int lmdidx = lmd - v.begin();
		dp[i] = i - lmdidx;// i 번째 녀석이 부순 갯수
		if (lmdidx > 0) {
			// i 번째 녀석이 부수지 못한 녀석이 부순 갯수
			dp[i] += dp[lmdidx - 1];
		}		
		ans = min(n - (i+1) + dp[i], ans);
	}
	cout << ans;
	return 0;
}