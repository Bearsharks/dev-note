#include <iostream>
using namespace std;

unsigned long long gcd(unsigned long long u, unsigned long long v) {
	if (v == 0) {
		return u;
	}
	else {
		return gcd(v, u % v);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	unsigned long long n, a, b, q, p;
	cin >> n>> a>> b>> q >> p;
	unsigned long long acnt = n / a;
	unsigned long long bcnt = n / b;
	unsigned long long abcnt = n / (a * b / gcd(a, b));
	if (q > p) {
		bcnt -= abcnt;
	}
	else {
		acnt -= abcnt;
	}
	cout << bcnt * p + acnt * q;
	return 0;
}