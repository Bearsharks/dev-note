#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int dp[1000] = { 0, };
	set<int> s;
	int ans = 1;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		set<int>::iterator end = s.upper_bound(a-1);
		int mx = 0;
		for (set<int>::iterator iter = s.begin(); iter != end; iter++) {
			mx = max(mx, dp[*iter]);
		}
		dp[a] = mx+1;
		ans = max(ans, dp[a]);
		s.insert(a);
	}
	cout << ans;
	return 0;
}