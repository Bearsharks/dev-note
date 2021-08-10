#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll d = 1000000007;
ll binpow(ll val, ll deg, ll mod) {
	if (!deg) return 1 % mod;
	if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
	ll res = binpow(val, deg >> 1, mod);
	return (res * res) % mod;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k == 0) {
			cout << 1 << '\n';
		}
		else if (n & 1) {
			cout << (binpow(2, k * n - 1, d) + 1) % d << "\n";
		}
		else {
			ll one = (binpow(2, n * k, d) - 1) % d;
			ll two = (binpow(2, n, d) - 1) % d;
			ll res = (one * binpow(two, d - 2, d) + 1) % d;
			cout << res << "\n";
		}
	}
	return 0;
}