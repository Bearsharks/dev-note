#include <iostream>
#include <vector>
using namespace std;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,m;
	cin >> n>>m;
	vector<vector<int>> v(n, vector<int>(m));
	int r, c, dir;
	cin >> r >> c >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	
	v[r][c] = 3;
	int result = 1;
	while (v[r][c] != 1) {		
		bool cango = false;
		for (int i = 1; i <= 4; i++) {
			int nextdir = (dir - i + 4) % 4;
			int nextr = dr[nextdir] + r;
			int nextc = dc[nextdir] + c;
			if (v[nextr][nextc] == 0) {
				r = nextr;	c = nextc; dir = nextdir;				
				v[r][c] = 3;
				result++;
				cango = true;
				break;
			}
		}
		if (!cango) {
			r = -dr[dir] + r;
			c = -dc[dir] + c;
		}
	}
	cout << result;
	return 0;
}