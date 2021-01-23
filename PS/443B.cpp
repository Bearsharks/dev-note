#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	int ans = 2;
	if (n <= (n + k) / 2) {
		cout << (n + k) - (n + k) % 2;
		return 0;
	}
	for (int l = 0; l < n; l++) {
		for (int r = l; r < n; r++) {
			int d = r - l + 1;
			string cur = s.substr(l, d);
			int nextl = r + 1;
			int cnt = 1;
			bool isok = true;
			while ( nextl + d - 1< n) {
				if (s.substr(nextl, d) != cur) {
					isok = false;
					break;					
				}
				cnt++;
				nextl = nextl + d;
			}
			if (!isok) {
				if (cnt > 1) {
					ans = max(ans, cnt * d);
				}				
				continue;
			}
			if (s.substr(l, n - nextl) == s.substr(nextl, n - nextl) && d <= n - nextl + k) {
				cnt++;
			}
			if (cnt > 1) {
				ans = max(ans, cnt * d);
			}			
		}
	}
	cout << ans;
	return 0;
}
