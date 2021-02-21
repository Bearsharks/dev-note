#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		ans += s[i] != s[i - 1];
	}
	cout << min(ans + 2, n);
	return 0;
}