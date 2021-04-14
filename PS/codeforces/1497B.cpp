#include <iostream>
#include <vector>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n,m;
		cin >> n >> m;
		vector<int> v(m);
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v[a % m]++;
		}
		for (int i = 1; i < m/2 + (m&1); i++) {
			int l = v[i];
			int r = v[m - i];
			if (l && r) {
				int k = min(l, r);
				n++;
				n -= min(2 * k + 1, l + r);
			}
		}
		if (m % 2 == 0 && v[m / 2]) {
			n -= v[m / 2];
			n++;		
		}
		if (v[0]) {
			n -= v[0];
			n++;
		}
		cout << n << "\n";
	}



	return 0;
}