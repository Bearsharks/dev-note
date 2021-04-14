#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	cout.setf(ios::fixed);
	cout.precision(15);
	while (t--) {
		int n;
		cin >> n;
		vector<double> dia;
		vector<double> miner;
		for (int i = 0; i < 2 * n; i++) {
			int x, y;
			cin >> x >> y;
			if (x == 0) miner.push_back(abs(y));
			else dia.push_back(abs(x));
		}
		sort(dia.begin(), dia.end());
		sort(miner.begin(), miner.end());
		double answer = 0;
		for (int i = 0; i < n; i++) {
			answer += sqrt(dia[i] * dia[i] + miner[i] * miner[i]);
		}
		cout << answer<<"\n";
	}
	return 0;
}