/*
* 안풀렸던 이유는 최대값의 범위를 잘못 잡았기 때문에 10 ^ 9 는 987654321보다 크다
* 1e9+1로 했어야 했다.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		int firstpositive = -1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int mn = 1e9 + 1;
		int first = 0;
		for (int i = 1; i < n; i++) {
			mn = min(abs(v[i] - v[i - 1]), mn);
			first = i;
			if (v[i] > 0) break;
		}
		if (v[first] <= mn) cout << first + 1 << "\n";
		else cout << first << "\n";
	}
	return 0;
}