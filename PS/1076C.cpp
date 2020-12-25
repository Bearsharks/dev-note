#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		cout.setf(ios::fixed);
		cout.precision(10);
		if (d == 0) {
			cout << "Y 0.0 0.0\n";
		}
		else if (d < 4) {
			cout << "N\n";
		}
		else if (d == 4) {
			cout << "Y 2.0 2.0\n";
		}
		else {
			double mx = d / 2.0;
			double mn = 1.0;
			double mid = (mx + mn) / 2.0;
			do {				
				double cur = (d - mid) * mid;
				if (d > cur) {
					mn = mid;
				}else {
					mx = mid;
				}
				mid = (mx + mn) / 2.0;
			} while ( abs(d - mid * (d - mid)) > 0.0000001 );
			cout << "Y " << d - mid << " " << mid << "\n";
		}		
	}
	
	return 0;
}