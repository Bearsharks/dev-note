#include <iostream>

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	if (n <= 3) {
		cout << "NO";
		return 0;
	}
	else if (n == 4) {
		cout << "YES\n1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
	}
	else if (n == 5) {
		cout << "YES\n5 * 3 = 15\n2 * 4 = 8\n15 + 8 = 23\n23 + 1 = 24\n";
	}else {
		cout << "YES\n";
		cout << "5 - 3 = 2\n2 - 2 = 0\n1 * 0 = 0\n";
		for (int i = 7; i <= n; i++) {
			cout << i << " * 0 = 0\n";
		}		
		cout << "6 * 4 = 24\n24 + 0 = 24\n";
	}
	return 0;
}