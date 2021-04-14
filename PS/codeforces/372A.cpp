#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int cur = n / 2;
	int ss = n;
	for (int i = 0; i < n / 2; i++) {
		while (cur < n && v[i] * 2 > v[cur]) {
			cur++;
		}
		if (cur == n) {
			cout << ss;
			return 0;
		}
		ss--;
		cur++;
	}
	cout << ss;
	return 0;
}