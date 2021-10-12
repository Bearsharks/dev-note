#include <iostream>
using namespace std;

typedef long long ll;

int mx = 987654321;
int mn = 100;
ll tgt;
int f(ll val, int cnt) {
	if (mn <= cnt || val > tgt) return mx;
	if (val == tgt) {
		mn = min(mn, cnt);
		return cnt;
	}
	return min(f(2 * val,cnt+1), f(val * 10 + 1,cnt+1));
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a,b;
	cin >> a >> b;
	tgt = b;
	ll answer = f(a, 1);
	if (answer == mx) answer = -1;
	cout << answer;
	return 0;
}