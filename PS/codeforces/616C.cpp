#include <iostream>
#include <vector>	
#include <set>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0, 1,0, -1 };
int isvisit[1000][1000] = { 0, };
vector<string> v(1000);
int n, m;
set<pair<int,int>> s;
int cnt = 1;
void dfs(pair<int, int> cur) {
	for (int i = 0; i < 4; i++) {
		int nextx = cur.first + dx[i];
		int nexty = cur.second + dy[i];
		if (0 <= nextx && nextx < n && 0 <= nexty && nexty < m) {
			if (v[nextx][nexty] != '.') {
				s.insert({ nextx, nexty });
			}
			else if (!isvisit[nextx][nexty]) {
				cnt++;
				isvisit[nextx][nexty] = 1;
				dfs({ nextx,nexty });
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '*') v[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!isvisit[i][j] && v[i][j] == '.') {
				isvisit[i][j] = 1;
				dfs({ i,j });
				for (pair<int, int> p : s) {
					v[p.first][p.second] = (v[p.first][p.second] + cnt) % 10;
				}
				cnt = 1;
				s.clear();
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(v[i][j] < 10) v[i][j] += '0';
		}
		cout << v[i] << "\n";
	}
	return 0;
}