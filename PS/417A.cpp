#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int c, d , n ,m,k;
	cin >> c >> d >> n >> m >> k;
	if (k >= n * m) {
		cout << 0;
		return 0;
	}

	int people = n * m - k;
	int a = people/n + 1, b = 0;
	int ans = INT_MAX;
	while (a >= 0) {
		ans = min(ans, c * a + d * b);
		a--;
		b = people - a * n;		
	}
	cout << ans;
	return 0;
}
