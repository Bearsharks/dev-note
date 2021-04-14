#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int m, t, r;
	cin >> m >> t >> r;
	vector<int> ghost(m);
	vector<int> candle;
	for (int i = 0; i < m; i++) {
		cin >> ghost[i];
	}
	if (t < r) {
		cout << -1;
		return 0;
	}
	int ans = 0;
	int lastOff = -1;
	for (int i = 0; i < m; i++) {
		for (int j = lastOff + 1; j < candle.size(); j++) {
			if (candle[j] <= ghost[i]) lastOff++;
		}
		int needcandle = r - (candle.size() - lastOff - 1);
		for (int j = 0; j < needcandle; j++) {
			candle.push_back(ghost[i] + t - needcandle + j + 1);
		}
	}
	cout << candle.size();
	return 0;
}