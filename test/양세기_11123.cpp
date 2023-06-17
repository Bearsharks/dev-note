#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> pos[4] = {{-1, 0},{1, 0},{0, -1}, {0, 1}};
vector<string> v(100);
int H, W;

void dfs(int x, int y) {
	v[x][y] = '.';
	for (int i = 0; i < 4; i++) {
		int nextX = x + pos[i].first;
		int nextY = y + pos[i].second;
		if (nextX > -1 && nextX < H && nextY > -1 && nextY < W && v[nextX][nextY] != '.') {
			dfs(nextX, nextY);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	
	
	for (int a = 0; a < t; a++) {
		cin >> H >> W;
		for (int b = 0; b < H; b++) {
			cin >> v[b];
		}
		int result = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (v[i][j] != '.') {
					result++;
					dfs(i, j);
				}
			}
		}
		cout << result << "\n";
	}

	return 0;
}