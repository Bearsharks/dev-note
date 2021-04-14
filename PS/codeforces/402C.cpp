#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, p;
		cin >> n >> p;
		int cnt = 2 * n + p;

		for (int i = 1; i < n && cnt; i++) {
			for (int j = i + 1; j <= n && cnt; j++) {
				cout << i << " " << j << "\n";
				cnt--;
			}
		}		
	}
	return 0;
}
