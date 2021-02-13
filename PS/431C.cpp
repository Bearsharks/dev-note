#include <iostream>
using namespace std;

int mo = 1e9 + 7;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,k,d;
	cin >> n >> k >> d;
	d--;
	int v[101] = { 1, 0,};
	int unn[101] = { 1, 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k && i+j <= n ; j++) {
			v[i + j] = (v[i+j] + v[i]) % mo;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= d && i + j <= n; j++) {
			unn[i+j] = (unn[i + j] + unn[i]) % mo;
		}
	}
	int ans = v[n] - unn[n];
	if (ans < 0) {
		ans += mo;
	}
	cout << ans;
	return 0;
}