#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int md = 1000000007;
	int n;
	cin >> n;
	int d = 1;
	int abc = 0;
	for (int i = 1; i <= n; i++) {
		int nd = abc;
		int nabc = (abc * 2LL + 3LL * d) % md;
		d = nd;
		abc = nabc;
	}
	cout << d;

	return 0;
}