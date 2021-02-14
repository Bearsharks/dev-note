#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<double> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	double mx = 0;
	cout.setf(ios::fixed);
	cout.precision(15);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		mx = max((v[a] + v[b]) / c, mx);
	}
	cout << mx;
	return 0;
}