#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int ans = n-1;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		vector<int> v(k);
		for (int j = 0; j < k; j++) {
			cin >> v[j];
		}
		if (v[0] == 1) {
			for (int j = 1; j < k; j++) {
				if(v[j] - v[j-1] == 1) cnt++;
				else 				break;
			}
		}
		ans += k - 1;
	}

	cout << ans - cnt * 2;
	return 0;
}