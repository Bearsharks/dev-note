#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		while (k > 3) {
			k--;
			n--;
			cout << 1 << " ";
		}
		if (n & 1) {
			n--;
			cout << 1 << " " << n / 2 << " " << n / 2 << "\n";
		}
		else {
			if (n % 4) {
				cout << (n-2) / 2 << " " << (n - 2) / 2 << " " << 2 << "\n";
			}
			else {
				cout << n/2 << " " << n / 4 << " " << n / 4 << "\n";
			}
		}
	}
	return 0;
}