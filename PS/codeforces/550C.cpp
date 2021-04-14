#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		int one = s[i] - '0';
		if (one % 8 == 0) {
			cout << "YES\n" << s[i];
			return 0;
		}
		for (int j = i+1; j < n; j++) {
			int two = s[j] - '0';
			if ((one * 10 + two) % 8 == 0) {
				cout << "YES\n" << s[i] << s[j];
				return 0;
			}
			for (int k = j+1; k < n; k++) {
				int three = s[k] - '0';
				if ((one * 100 + two*10 + three) % 8 == 0) {
					cout << "YES\n" << s[i]<< s[j]<< s[k];
					return 0;
				}
			}
		}
	}
	cout << "NO";
	return 0;
}