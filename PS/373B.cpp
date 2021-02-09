#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll degitcnt(ll a) {
	ll result = 0;
	while (a != 0) {
		a /= 10;
		result++;
	}
	return result;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	ll w, m, k;
	cin >> w >> m >> k;
	ll a = 1;
	int cur = degitcnt(m); 
	for (int i = 0; i < cur; i++) {
		a *= 10;
	}
	ll ans = 0;
	while ((a - m) < w / (cur * k)) {
		w -= (a - m) * cur * k;
		ans += (a - m);
		m = a;
		a *= 10;		
		cur++;
	}
	ans += w / (cur*k);
	cout << ans;
	return 0;
}