#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	if (n & 1) {
		cout << -1;
		return 0;
	}

	string s[2] = { "","" };
	string str[2] = { "bb","ww" };
	for (int k = 0; k < n/2; k++) {
		s[0] += str[k%2];
		s[1] += str[(k+1) % 2];
	}
	int cur = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << s[cur++%2] << "\n";
		}
		cur += i % 2;
		cout << "\n";
	}
	return 0;
}