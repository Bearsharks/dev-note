#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(9);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<long long> v(n);
		long long sum = 0;
		long long mx = -1e10;
		while (n--) {
			cin >> v[n];
			mx = max(mx, v[n]);
			sum += v[n];
		}
		sum -= mx;
		cout <<  mx + sum * 1.0 / (v.size()-1) << "\n";
	}
	return 0;
}