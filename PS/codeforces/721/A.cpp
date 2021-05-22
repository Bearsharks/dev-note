#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int cnt = 0;
		while (n) {
			n = n >> 1;
			cnt++;
		}
		cout << (1 << cnt - 1)-1 << "\n";
	}
	return 0;
}