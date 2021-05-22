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
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int cur = 0;
		while (k && cur < n-1) {
			if (v[cur] > k) {
				v[cur] -= k;
				v[n - 1] += k;
				k = 0;				
			}
			else {
				k -= v[cur];
				v[n - 1] += v[cur];
				v[cur] = 0;
			}
			cur++;
		}
		for (int i : v) {
			cout << i << ' ';
		}
		cout << "\n";
	}
	
	return 0;
}