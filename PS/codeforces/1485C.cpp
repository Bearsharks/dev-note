#include <iostream>

using namespace std;
typedef long long ll;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		ll ans = 0;
		ll k = 1;
		while (k*k + 2*k <= x) {
			//mxb = y but upper_bound -> y+1 
			ll mxb = y+1;
			ll mnb = k+1;
			while (mnb < mxb) {
				ll mid = (mxb + mnb) / 2;
				if (k * mid + k <= x) {
					mnb = mid + 1;
				}
				else {
					mxb = mid;
				}
			}
			ans += max((ll)0, mxb - (k+1));
			k++;
		}
		cout << ans << "\n";
	}
	

	return 0;
}