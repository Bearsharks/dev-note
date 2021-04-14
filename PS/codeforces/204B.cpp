#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	unordered_map<int,int> upside(n);
	unordered_map<int,int> downside(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		
		upside[a]++;
		downside[a];

		if (a == b) continue;
		upside[b];
		downside[b]++;
		
	}

	int mn = INT_MAX;
	for (pair<int, int> p : upside) {
		int cnt = p.second + downside[p.first];
		if (n/2 + (n&1) <= cnt) {
			int candi = max(n / 2 + (n & 1) - p.second, 0);
			mn = min(mn,candi);
		}
	}
	if (mn == INT_MAX) {
		mn = -1;
	}
	cout << mn;
	return 0;
}