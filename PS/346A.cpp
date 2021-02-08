#include <iostream>
using namespace std;

int gcd(int u, int v) {
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
	int n;
	cin >> n;
	int mx;
	cin >> mx;
	int g = mx;
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		mx = max(a, mx);
		g = gcd(a, g);
	}	
	int total = mx / g;
	if ((total - n) & 1) {
		cout << "Alice";
	}
	else {
		cout << "Bob";
	}
	return 0;
}