#include <iostream>

using namespace std;
typedef long long ll;
int amain() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		ll ans = 0;
		for (ll i = 2; i <= b; i++) {
			ll k = min(i * i - 1, a);			
			ll cur = k / (i + 1);
			ans += cur;
			if (cur == 0) break;
		}
		cout << ans << "\n";
	}
	

	return 0;
}