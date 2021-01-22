#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(6);
	double a, d;
	int n;
	cin >> a >> d >> n;

	for (int i = 1; i <= n; i++) {
		unsigned long long  curint = d * (unsigned long long)i / a;
		double goodtogo = d * i - a * curint;// a * (d * n / a - curint)
		curint = curint % 4;
		pair<double, double> cur;

		if (curint == 0) {
			cur ={ goodtogo , 0 };
		}
		else if (curint == 1) {
			cur = { a, goodtogo };
		}
		else if (curint == 2) {
			cur = { a - goodtogo,a };
		}
		else {
			cur = { 0 , a - goodtogo };
		}
		cout << cur.first << " " << cur.second << "\n";
	}
	return 0;
}
