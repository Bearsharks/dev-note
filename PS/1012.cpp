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
	int t;
	cin >> t;
	while (t--) {
		int n, r, c;
		cin >>  r >> c >> n;
		vector<vector<bool>> v(r, vector<bool>(c,false));
		vector<vector<bool>> isvisit(r, vector<bool>(c, false));
		int answer = 0;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v[a][b] = true;
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (v[i][j]&&!isvisit[i][j]) {
					answer++;
					dfs(i, j, v,isvisit);
				}
			}			
		}		
		cout << answer << "\n";
	}
	
	return 0;
}