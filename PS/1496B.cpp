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
		int n, k;
		vector<int> v;
		cin >> n >> k;

		
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		if (k == 0) {
			cout << n << "\n";
			continue;
		}
		sort(v.begin(), v.end());

		int mex = 0;
		if (v[0] == 0) {
			for (int i = 1; i < n; i++) {
				if (v[i] - v[i - 1] > 1) {
					mex = v[i - 1] + 1;
					break;
				}
			}
			if (mex == 0) {
				mex = v.back() + 1;
			}
		}		
		int max = v.back();
		if (max < mex) {
			cout << n + k << "\n";
		}
		else {
			int test = ((max + mex) / 2) + ((max + mex) & 1);
			vector<int>::iterator titer = lower_bound(v.begin(), v.end(), test);
			cout << n + (*titer != test) << "\n";
		}
	}
	return 0;
}