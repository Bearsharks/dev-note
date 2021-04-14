#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	double m , n;
	cin >> m >> n;
	double ans = m;

	
	for (int i = 1; i < m; i++) {
		ans -= pow(i / m, n);
	}
	cout.setf(ios::fixed);
	cout.precision(6);
	cout << ans;
	return 0;
}