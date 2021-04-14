#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map<int, int> m;
	int prevboxsize = -1;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		m[a] += b;
	}
	int mx = m.rbegin()->first;
	for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == 1) continue;
		m[iter->first +1] = max(m[iter->first + 1],iter->second / 4 + !!(iter->second % 4));
	}
	int a = m.rbegin()->first;
	int b = m.rbegin()->second;
	while (b > 1) {
		a++;
		b = b / 4 + !!(b % 4);
	}
	cout << ((mx >= a) ? mx+1 : a);
	return 0;
}