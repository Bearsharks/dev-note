#include <iostream>
#include <vector>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string t;
	cin >> t;
	string s;
	cin >> s;

	vector<int> tcs(10);
	for (char c : t) {
		int cur = c - '0';
		if (cur == 5) cur = 2;
		if (cur == 9) cur = 6;
		tcs[cur]++;
	}
	vector<int> scs(10);
	for (char c : s) {
		int cur = c - '0';
		if (cur == 5) cur = 2;
		if (cur == 9) cur = 6;
		scs[cur]++;
	}
	int ans = INT_MAX;
	for (int i = 0; i < 10; i++) {
		if (tcs[i] == 0) continue;
		ans = min(ans, scs[i] / tcs[i]);
	}
	cout << ans;
	return 0;

}
