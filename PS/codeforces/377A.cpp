#include <iostream>
#include <vector>
using namespace std;

vector<string> v(500);
vector<vector<int>> visit(500, vector<int>(500));
vector<pair<int, int>> d = { {-1,0},{0,1},{1,0},{0,-1} };
int n, m, k;
void dfs(int i, int j) {	
	if (k == 0) return;
	visit[i][j] = true;
	bool cango = false;
	for (int a = 0; a < 4; a++) {
		int nexti = i + d[a].first;
		int nextj = j + d[a].second;
		if (0 <= nexti && nexti < n && 0 <= nextj && nextj <= m && v[nexti][nextj] == '.' && visit[nexti][nextj] == false) {
			cango = true;		
			dfs(nexti, nextj);
		}
	}
	if (k == 0) return;
	v[i][j] = 'X';
	k--;	
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {	
			if (v[i][j] == '.' && visit[i][j] == false)	dfs(i, j);
			if (k == 0) {
				for (int i = 0; i < n; i++) {
					cout << v[i] << "\n";
				}
				return 0;
			}
		}
	}
	
	return 0;
}