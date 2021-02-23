#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, d,h;
	cin >> n >> d >> h;
	if (d > h * 2) {
		cout << -1;
		return 0;
	}
	if (n < 3) {
		cout << 1 << " " << 2;
		return 0;
	}
	int p = 1, c= 2;
	for (int i = 0; i < h; i++) {
		cout << p++ << " " << c++ <<"\n";
	}
	p = 1;
	for (int i = h; i < d; i++) {
		cout << p << " " << c << "\n";
		p = c++;		
	}
	for (int i = c; i <= n; i++) {
		cout << "1 " << i << "\n";
	}
	return 0;
}