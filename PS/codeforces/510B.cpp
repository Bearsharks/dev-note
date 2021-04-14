#include <iostream>
#include <vector>
using namespace std;

int isvisit[50][50] = { 0, };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
vector<string> v(50);

bool dfs(pair<int, int> start, pair<int, int> cur,int k) {
	isvisit[cur.first][cur.second] = 1;
	for (int i = 0; i < 4; i++) {
		int nextx = cur.first + dx[i];
		int nexty = cur.second + dy[i];		
		if (0 <= nextx && nextx < n && 0 <= nexty && nexty < m
			&& v[nextx][nexty] == v[start.first][start.second])			
		{
			if (nextx == start.first && nexty == start.second && k >= 4) {
				return true;
			}
			if (!isvisit[nextx][nexty] && dfs(start, { nextx, nexty }, k + 1)) return true;
		}
	}
	isvisit[cur.first][cur.second] = 0;
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n>>m;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int curvisit = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			pair<int, int> start = { i,j };
			if (!isvisit[i][j] && dfs(start,start,1)) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}