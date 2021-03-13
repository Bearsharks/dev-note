#include <iostream>

using namespace std;
typedef long long ll;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;

		int prev = INT_MAX;			
		int cntinc = (b == 1);
		while (1) {			
			int cura = a;
			int cntdiv = 0;
			while (cura > 0) {
				cura /= (b + cntinc);
				cntdiv++;
			}
			if (prev < cntdiv + cntinc) break;
			prev = cntdiv + cntinc;
			cntinc++;			
		};
		cout << prev << "\n";
	}

	return 0;
}