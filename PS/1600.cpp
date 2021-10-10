#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int dhx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dhy[8] = { 1,2,2,1,-1,-2,-2,-1 };

struct MoveInfo {
	int r, c, totalMove, horseMove;
};
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int k, n,m;
	cin >> k>>m>>n;

	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	vector<vector<vector<int>>> minCost(n, vector<vector<int>>(m,vector<int>(32,987654321)));
	minCost[0][0][0] = 0;
	//위치, 전체횟수, 말이동횟수 
	queue<MoveInfo> q;
	q.push({ 0,0,0,0 });
	while (!q.empty()) {
		MoveInfo info = q.front(); q.pop();
		int r = info.r;
		int c = info.c;
		int total = info.totalMove;
		int horseMove = info.horseMove;
		if (minCost[r][c][horseMove] < total) continue;
		for (int i = 0; i < 4; i++) {
			int nextr = r + dx[i];
			int nextc = c + dy[i];
			if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < m && 
				v[nextr][nextc] == 0 && minCost[nextr][nextc][horseMove] > total + 1)
			{
				minCost[nextr][nextc][horseMove] = total + 1;
				q.push({ nextr,nextc,total + 1, horseMove });
			}
		}
		if (horseMove >= k) continue;

		for (int i = 0; i < 8; i++) {
			int nextr = r + dhx[i];
			int nextc = c + dhy[i];
			if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < m &&
				v[nextr][nextc] == 0 && minCost[nextr][nextc][horseMove+1] > total + 1)
			{
				minCost[nextr][nextc][horseMove+1] = total + 1;
				q.push({ nextr,nextc,total + 1, horseMove + 1});
			}
		}
	}
	int answer = 987654321;
	for (int i = 0; i <= k; i++) {
		answer = min(answer, minCost[n - 1][m - 1][i]);
	}
	if (answer == 987654321) answer = -1;
	cout << answer;
	return 0;
}