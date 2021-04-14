#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	queue<int> q;
	int lasthash = 0;
	int hashcnt = 0;
	int remain = 0;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == '(') {
			if (!q.empty()) {
				s[q.front()] = '0';
				q.pop();
				s[i] = '0';
			}
			else {
				remain++;
			}
		}
		else {
			q.push(i);
			if (s[i] == '#') {
				lasthash = max(lasthash,i);
				hashcnt++;
			}
		}
	}
	if (!q.empty()) {
		cout << -1;
		return 0;
	}
	for (int i = lasthash+1; i < n; i++) {
		if (s[i] == '(') {
			cout << -1;
			return 0;
		}
	}
	for (int i = 0; i < hashcnt-1; i++) {
		cout << "1\n";
	}
	cout << 1 + remain;
	return 0;
}