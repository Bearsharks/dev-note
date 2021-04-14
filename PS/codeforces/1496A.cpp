#include <iostream>

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		int cnt = 0;
		for (int l = 0, r = n - 1; (l+ !(n & 1) ) < r; l++, r--) {
			if (s[l] != s[r]) {
				break;
			}
			cnt++;
		}
		if (cnt >= k) {
			cout << "YES\n";
		}else {
			cout << "NO\n";
		}
	}
	return 0;
}