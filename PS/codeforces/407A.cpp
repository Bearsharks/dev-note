#include <iostream>
#include <cmath>
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
	int a, b;
	cin >> a >> b;
	for (int i = 1; i < a; i++) {
		int j = (int)sqrt(a * a - i * i);
		if (j * j + i * i == a * a) {
			int g = gcd(j, i);
			int bi = j / g;
			int bj = i / g;
			int mn = bi * bi + bj * bj;
			int cur = 1;
			while (cur * cur * mn < b * b) {
				cur++;
			}
			if (cur * cur * mn == b * b && bj*cur !=j) {
				cout << "YES\n";
				cout << "0 0\n" << -i << " " << j << "\n" << bi* cur << " " << bj* cur;
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}