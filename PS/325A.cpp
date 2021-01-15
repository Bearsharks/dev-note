#include <iostream>

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int mxx = -1, mxy = -1, mnx = INT_MAX, mny = INT_MAX;
	int sum = 0;
	while (n--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		sum += (c - a) * (d - b);
		mnx = min(mnx, a);
		mny = min(mny, b);
		mxx = max(mxx, c);
		mxy = max(mxy, d);
	}
	if (sum == (mxx - mnx) * (mxy - mny) && mxx - mnx == mxy - mny) cout << "YES";
	else cout << "NO";
	return 0;
}
