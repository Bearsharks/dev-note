#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> d[4] = { {-1,0},{0,1},{1,0},{0,-1} };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	vector<string> v;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		v.push_back(a);
	}
	
	vector<pair<int, int>> t;
	int myt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] && v[i][j] == 'E') {
				queue<pair<int, int>> q;
				queue<int> cq;
				int cnt = 0;
				q.push({ i,j });
				cq.push(0);
				v[i][j] = 'T';
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					int cnt = cq.front(); cq.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.first + d[k].first;
						int ny = cur.second + d[k].second;
						if (nx < 0 || n <= nx || ny < 0 || m <= ny || v[nx][ny] == 'T') {
							continue;
						}
						if (v[nx][ny] == 'S') {
							myt = cnt + 1;
						}
						else if (v[nx][ny] > '0' && v[nx][ny] <= '9') {
							t.push_back({ v[nx][ny] - '0', cnt + 1 });
						}
						v[nx][ny] = 'T';
						q.push({ nx, ny });
						cq.push(cnt + 1);
					}
				}
				break;
			}
		}
	}

	int ans = 0;
	for (pair<int,int> p : t) {
		if(p.second <= myt) ans += p.first;
	}
	cout << ans;
	return 0;
}