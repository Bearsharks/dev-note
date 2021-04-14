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

	
	unsigned long long n = 0;
	cin >> n;
	if (n < 3) {
		cout << n;
		return 0;
	}
	if (n & 1) {
		cout << n * (n - 1) * (n - 2);
	}
	else {
		if (gcd(n, n - 3) == 1) {
			cout << n * (n - 1) * (n - 3);			
		}
		else {
			cout << (n - 1) * (n - 2) * (n - 3);
		}
		
	}
	return 0;
}