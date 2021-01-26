#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int ab = -1;
	int ba = -1;
	int n = s.size();
	for (int i = 0; i < n-1; i++) {
		if (s[i] == 'A' && s[i + 1] == 'B') {
			if (ab == -1) ab = i;
			if (ba != -1 && ba + 1 < i) {
				cout << "YES";
				return 0;
			}
		}
		else if (s[i] == 'B' && s[i + 1] == 'A') {
			if (ba == -1) ba = i;
			if (ab != -1 && ab+1 < i) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}