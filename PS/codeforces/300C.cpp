#include <iostream>
#include <vector>
using namespace std;

int d = 1e9 + 7;
long long fact[1000001];

long long binpow(long long val, long long deg, long long mod) {
	if (!deg) return 1 % mod;
	if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
	long long res = binpow(val, deg >> 1, mod);
	return (res * res) % mod;
}

void initfact(int n) {
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = (i * fact[i-1]) % d;
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long a, b, n;
	cin >> a >> b >> n;
	long long ans = 0;
	initfact(n);
	for (int i = 0; i <= n; i++) {
		long long cur = a * i + b * (n - i);
		long long isbeautiful = true;
		while (cur >= 1) {
			long long remain = (cur % 10);
			if (remain != a && remain != b) {
				isbeautiful = false;
				break;
			}
			cur /= 10;
		}
		if (isbeautiful) {
			ans = (ans + fact[n] * binpow( (fact[i]*fact[n-i]) % d , d-2, d) ) % d;
		}
	}
	cout << ans;
	return 0;
}