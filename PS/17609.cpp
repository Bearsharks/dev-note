#include <iostream>

using namespace std;
typedef long long ll;

bool isPalindrome(int l, int r, string& s) {
	while (l < r) {
		if (s[l] != s[r]) return false;
		++l; --r;
	}
	return true;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int l = 0, r = s.size() - 1;
		int res = 0;
		while (l < r) {
			if (s[l] != s[r]) {
				if ((isPalindrome(l + 1, r, s) || isPalindrome(l, r - 1, s))) res = 1;
				else res = 2;
				break;
			}
			++l; --r;
		}
		cout << res << "\n";
	}
	return 0;
}