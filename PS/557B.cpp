#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,w;
	cin >> n >> w;
	vector<int> v(2*n);
	for (int i = 0; i < 2*n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	double ans = min(v[n] / (double)2, (double)v[0]);
	ans = min(w / ((double)3 * n), ans);
	cout.setf(ios::fixed);
	cout.precision(8);
	cout << ans * 3 * n;
	return 0;
}