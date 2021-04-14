#include <iostream>
#include <vector>
using namespace std;

long long d = 1e9 + 7;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long a, b;
	cin >> a >> b;
	long long ans = 0;
	
	long long s;
	if ((a & 1) == 1) {
		s = ((b + 1 + a * b + 1) / 2) % d;
		s = (s * a) % d;
	}
	else {
		s = (b + 1 + a * b + 1) % d;
		s = (s * a/2) % d;
	}
	
	for (int i = 1; i < b; i++) {
		ans = (ans + s * i) % d;
	}
	cout << ans;
	return 0;
}