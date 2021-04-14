#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

ll gcd(ll u, ll v) {
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
	ll n;
	cin >> n;
	vector<ll> v(n);
	vector<ll> cnt(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	ll every = 0;
	for (int i = 1; i < n; i++) {
		every += (n - i) * i * abs(v[i] - v[i-1]);
	}
	ll numerator = every*2 + sum;

	ll g = gcd(numerator, n);
	cout << numerator / g << " " << n / g;
	return 0;
}