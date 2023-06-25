#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

pair<int, int> p[] = { {-1,0}, {0,1}, {1,0}, {0, -1} };
vector<vector<int>> v;
int n, mn, mx;

void dfs(int i, int j, vector<vector<int>>& group, int key) {
	group[i][j] = key;
	for (int k = 0; k < 4; k++) {
		int x = i + p[k].first;
		int y = j + p[k].second;
		if (0 <= x && x < n && 0 <= y && y < n && group[x][y] == 0) {
			int diff = abs(v[x][y] - v[i][j]);
			if (mn <= diff && diff <= mx) {
				dfs(x, y, group, key);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> mn >> mx;

	v.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	int day = 0;
	while(true) {
		vector<vector<int>> group(n, vector<int>(n));
		int curGroupKey = 1;
		// 1. 속하는 연합이 없다면 연합 지정 함.
		// 우 하 비교 후 가능하면 현재 연합에 포함
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (group[i][j] == 0) {
					dfs(i, j, group, curGroupKey++);
				}
			}
		}
		// 2. 모든 연합을 뽑아냄.
		unordered_map<int, vector<pair<int,int>>> groupMap;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int groupId = group[i][j];
				groupMap[groupId].push_back({ i, j });
			}
		}

		// 3. 인구이동 가능?
		if (groupMap.size() == n * n) {
			break;
		}

		// 4. 연합을 돌면서 인구이동 시작
		for (auto& group : groupMap) {
			vector<pair<int, int>>& 국가들 = group.second;
			int 인구 = 0;
			for (pair<int, int> p : 국가들) {
				인구 += v[p.first][p.second];
			}
			인구 /= 국가들.size();
			for (pair<int, int> p : 국가들) {
				v[p.first][p.second] = 인구;
			}
		}
		day++;
	}

	cout << day;

	return 0;
}