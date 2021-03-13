#include <iostream>
using namespace std;

typedef unsigned long long ull;

int gcd(int u, unsigned int v) {
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
	int a,b,n,m,x,y;
	cin >> n>> m>> x>> y>> a>> b;
	int g = gcd(a, b);
	a /= g;
	b /= g;
	double k = min(n/a,m/b);
	double x2 = x + (k*a) / 2;
	double y2 = y + (k*b) / 2;
	double x1 = x - (k * a) / 2;
	double y1 = y - (k * b) / 2;
	bool isintx = x2 == (int)x2;
	bool isinty = y2 == (int)y2;
	if (x2 > n) {
		isintx = true;
		x1 -= x2 - n;
		x2 = n;
	}
	else if (x1 < 0) {
		isintx = true;
		x2 += 0 - x1;
		x1 = 0;
	}
	if (y2 > m) {
		isinty = true;
		y1 -= y2 - m;
		y2 = m;
	}
	else if (y1 < 0) {
		isinty = true;
		y2 += 0 - y1;
		y1 = 0;
	}
	if (!isintx) {
		x1 -= 0.5;
		x2 -= 0.5;
	}
	if (!isinty) {
		y1 -= 0.5;
		y2 -= 0.5;
	}
	cout << (int)x1 << " " << (int)y1 << " " << (int)x2 << " " << (int)y2;
	return 0;
}