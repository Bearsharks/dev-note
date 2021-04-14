#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull d = 1e9 + 9;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	ull n, m, k;
	cin >> n >> m >> k;
	ull cnt = (n / k) * (k - 1) + (n % k);
	ull ans = 0;
	if (cnt >= m) ans = m;
	else {
		ull doublecnt = m - cnt;
		ull remain = m - doublecnt * k;
		ans = 2;
		while (doublecnt > 30) {
			ans = (ans << 30) % d;
			doublecnt -= 30;
		}
		while (doublecnt > 0) {
			ans = (ans << 1) % d;
			doublecnt--;
		}
		
		if (ans < 2) ans += d;
		ans -= 2;
		ans = (k * ans) % d;
		ans = (ans + remain) % d;
	}
	cout << ans;
	return 0;
}