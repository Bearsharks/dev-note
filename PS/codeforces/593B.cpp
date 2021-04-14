#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<double, int>> v1(n);
	vector<pair<double, int>> v2(n);
	
	double x1, x2;
	cin >> x1 >> x2;
	x1 += 1e-9;
	x2 -= 1e-9;
	for (int i = 0; i < n; i++) {
		long long k, b;
		cin >> k>>b;
		v1[i] = { k * x1 + b, i };
		v2[i] = { k * x2 + b, i };
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < n; i++) {
		if (v1[i].second != v2[i].second) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}