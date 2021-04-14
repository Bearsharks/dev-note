#include <iostream>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t, s, q;
	cin >> t >> s >> q;

	int next = s * q;
	int ans = 1;
	while (next < t) {
		s = next;
		next = s * q;
		ans++;
	}
	cout << ans;
	return 0;
}