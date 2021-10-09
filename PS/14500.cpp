#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
void dfs(int i, int j, vector<vector<bool>>& v, vector<vector<bool>>& isvisit) {
	isvisit[i][j] = true;
	int n = v.size();
	int m = v[0].size();
	for (int k = 0; k < 4; k++) {
		int nextr = i + dx[k];
		int nextc = j + dy[k];
		if (0 <= nextr && nextr < n && 0 <= nextc && nextc < m && v[nextr][nextc] && !isvisit[nextr][nextc]) {
			dfs(nextr, nextc, v, isvisit);
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int r, c;
	cin >> r >> c;
	vector<vector<int>> v(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> v[i][j];
		}
	}
	return 0;
}