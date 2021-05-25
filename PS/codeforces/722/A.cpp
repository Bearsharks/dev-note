#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		if (n == 1) {
			cout << "0" << "\n";
			continue;
		}
		sort(v.begin(), v.end());
		int answer = 1;
		for (int i = 1; i < n; i++) {			
			if (v[0] == v[i]) answer++;
			else break;
		}
		cout << n - answer << "\n";
	}
	return 0;
}