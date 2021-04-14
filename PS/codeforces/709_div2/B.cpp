#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		set<int> s;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			mx = max(mx, v[i]);
		}

		bool isfail = false;
		for (int i = 1; i < n; i++) {
			s.insert(v[i] - v[i - 1]);
		}
		if (s.size() > 2) {
			cout << -1 << "\n";
		}
		else if (s.size() <= 1) {
			cout << 0 << "\n";
		}
		else {
			int fir = *(s.begin());
			int se = *(s.rbegin());
			if((ll)fir * se >= 0) cout << -1 << "\n";
			else {
				if (se < fir) swap(se, fir);
				int candi = se - fir;
				if (candi > mx) {
					cout << candi << " " << se << "\n";
				}
				else {
					cout << -1 << "\n";
				}
			}
		}
	}
	return 0;
}