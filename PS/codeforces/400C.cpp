#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	unsigned long long n, m, x, y, z, p;
	cin >> n >> m >> x >> y>> z >> p;
	y = y & 1;
	if (y) {
		x = ((x + z) * 3) % 4;
	}
	else {
		x = (x + (z * 3) )% 4;
	}	

	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		pair<int, int> coord = { a,b };
		if (y) {
			coord = { coord.first, m - coord.second + 1 };
		}
		if (x == 1) {
			coord = { coord.second, n - coord.first + 1 };
		}
		else if (x == 2) {
			coord = { n - coord.first + 1, m - coord.second + 1 };
		}
		else if (x == 3) {
			coord = { m - coord.second + 1, coord.first };
		}
		cout << coord.first << " " << coord.second << "\n";
	}
	return 0;
}
