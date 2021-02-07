#include <iostream>
using namespace std;

typedef long long ll;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	ll a,b;
	cin >> a >> b;
	ll ans = 0;
	while (a % b != 0) {
		ans += a / b;
		a = a % b;
		ll tmp = b;
		b = a;
		a = tmp - a;
		ans++;
	}
	cout << ans+a/b;
	return 0;
}