#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
while (t--) {
	string chessboard[8];
	vector<pair<int, int>> v;
	int knight = '1';
	for (int i = 0; i < 8; i++) {
		cin >> chessboard[i];
		for (int j = 0; j < 8; j++) {
			if (chessboard[i][j] == 'K') {
				v.push_back({ i,j });
				chessboard[i][j] = '.';
			}
		}
	}
	int dx = abs(v[0].first - v[1].first);
	int dy = abs(v[0].second - v[1].second);

	bool canmeet = dx % 2 + dy % 2 + (dx / 2) % 2 + (dy / 2) % 2 == 0;
	if (canmeet) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}
	return 0;
}
