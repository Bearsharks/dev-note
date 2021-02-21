#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map<int, int> m; 
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		m[v[i]]++;
	}
	int cnt = 0;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		if (m[v[i]]-- == 1) m.erase(v[i]);
		mx = max(v[i], mx);
		map<int, int>::iterator iter = m.upper_bound(mx-1);
		if (iter == m.begin()) {
			cnt++;
			mx = 0;
		}
	}
	cout << cnt;
	return 0;
}