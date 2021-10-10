#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<bool>> isOut;
int n, m;
vector<pair<int, int>> candis;
struct EraseListInfo {
	int x, y, cnt;
};
bool dfs(vector<vector<int>>& v, pair<int, int> cur, queue<EraseListInfo>& eraseList, int cnt) {
	isOut[cur.first][cur.second] = true;
	for (int i = 0; i < 4; i++) {
		int nextx = cur.first + dx[i];
		int nexty = cur.second + dy[i];
		if (0 <= nextx && nextx < n && 0 <= nexty && nexty < m) {
			//치즈인경우
			if (v[nextx][nexty]){
				if (v[nextx][nexty] < 3) {
					v[nextx][nexty]++;
					if (v[nextx][nexty] >= 3) {
						eraseList.push({ nextx, nexty,cnt+1});
					}
				}
			}
			else if(!isOut[nextx][nexty]){
				dfs(v, { nextx, nexty }, eraseList, cnt);
			}
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	isOut.assign(n, vector<bool>(m,false));
	//외부표시하기 하면서 2개 이상 닿은 치즈 표시
	//표시된 치즈 지우기 그 치즈 외부표시하기
	queue<EraseListInfo> eraseList;
	eraseList.push( {0,0,0} );
	int answer = 0;
	while (eraseList.size()) {
		EraseListInfo cur = eraseList.front(); eraseList.pop();
		v[cur.x][cur.y] = 0;
		dfs(v, { cur.x, cur.y }, eraseList, cur.cnt);
		answer = max(answer, cur.cnt);
	}	
	cout << answer;
	return 0;
}