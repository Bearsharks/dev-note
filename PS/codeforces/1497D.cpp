#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

vector<ll> dp(5000);
vector<ll> tag(5000);
vector<ll> score(5000);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		
		int n;
		cin >> n;
		dp.assign(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> tag[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> score[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (tag[i] == tag[j]) continue;
				ll sj = dp[j];
				ll si = dp[i];
				ll s = abs(score[i] - score[j]);
				dp[j] = max(dp[j], si + s);
				dp[i] = max(dp[i], sj + s);
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, dp[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}