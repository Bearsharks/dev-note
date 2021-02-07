#include <iostream>
#include <vector>
using namespace std;

long long d = 1e9 + 7;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string x;
	cin >> x;
	int n = x.size();
	long long cur = 1;
	for (int i = 1; i < n; i++) {
		cur = (cur << 1) % d;
	}
	long long ans = 0;
	for (int i = n-1; i >= 0; i--) {
		if (x[i] == '1') {
			ans = (ans + cur) % d;
		}
		cur = (cur << 1) % d;
	}
	cout << ans;
	return 0;
}