#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int ans = 0;

bool dfs(vector<string>& v, vector<vector<bool>>& visit, int i, int j) {
	visit[i][j] = true;
	if (j == m - 1) {
		ans++;
		return true;
	}
	int nextj = j + 1;
	for (int nexti = i - 1; nexti <= i + 1; nexti++) {
		if (nexti >= 0 && nexti < n && nextj < m && visit[nexti][nextj] == false && v[nexti][nextj] == '.' && dfs(v, visit, nexti, nextj)) {
			return true;
		}
	}
	return false;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);	
	cin >> n>>m;
	vector<string> v(n);
	vector<vector<bool>> visit(n,vector<bool>(m));
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	for (int i = 0; i < n; i++) {
		if (v[i][0] == '.') {
			dfs(v,visit,i,0);
		}
	}

	cout << ans;
	return 0;
}