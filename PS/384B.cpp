#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m, order;
	cin >> n >> m >> order;
	cout << m * (m - 1) / 2;
	for (int i = 1; i < m; i++) {
		for (int j = i + 1; j <= m; j++) {
			if (order) {
				cout << "\n" << j << " " << i;
			}
			else {
				cout << "\n" << i << " " << j;
			}			
		}
	}
	return 0;
}
