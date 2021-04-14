#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

long long binpow(long long val, long long deg, long long mod) {
	if (!deg) return 1 % mod;
	if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
	long long res = binpow(val, deg >> 1, mod);
	return (res * res) % mod;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string a;
	ll k;
	cin >> a >> k;
	ll twos = binpow(2, a.size(), mod);
	ll inverse = binpow((twos - 1 + mod)%mod, mod - 2, mod);
	ll twosk = binpow(twos, k, mod);
	ll x = 0;
	ll cur = 1;
	for (int i = 0; i < a.size();i++) {
		int num = a[i] - '0';
		
		if (num == 0 || num == 5) {
			x = (x + cur) % mod;
		}
		cur = (cur << 1) % mod;
	}
	cout << (((x * twosk - x + mod) % mod) * inverse) % mod;
	return 0;
}