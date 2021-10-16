#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;

const int INF = 987654321;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void print(vector<vector<int>>& v) {
	int n = v.size();
	int m = v[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

class Baby {
public:
	Baby(pair<int, int> pos_, vector<vector<int>>& map_) :pos(pos_), map(map_) {}
	bool canEat(pair<int, int> tgtPos) {
		return map[tgtPos.first][tgtPos.second] && size > map[tgtPos.first][tgtPos.second];
	}
	bool canMove(pair<int, int> tgtPos) {
		return size >= map[tgtPos.first][tgtPos.second];
	}
	void eat(pair<int, int> tgtPos) {
		if (canEat(tgtPos)) {
			map[pos.first][pos.second] = 0;
			map[tgtPos.first][tgtPos.second] = 9;
			cnt++;
			if (cnt >= size) {
				cnt = 0;
				size++;
			}
		}
	}
	pair<int, int> pos;
private:
	vector<vector<int>>& map;
	int size = 2;
	int cnt = 0;
};
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> v(n,vector<int>(n,0));
	pair<int, int> babyPos;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			if (v[i][j] == 9) {
				babyPos = { i,j };
			}
		}
	}

	int answer = 0;
	Baby baby(babyPos, v);	
	bool needHelp = false;
	while (!needHelp) {
		pair<int, int> tgt = { INF,INF };
		int minCost = INF;
		vector<vector<int>> costs(n, vector<int>(n, INF));
		queue<tuple<int, int, int>> q;
		q.push({ baby.pos.first, baby.pos.second, 0 });
		costs[baby.pos.first][baby.pos.second] = 0;
		while (!q.empty()) {
			tuple<int, int, int> cur = q.front(); q.pop();
			int r = get<0>(cur);
			int c = get<1>(cur);
			int cost = get<2>(cur);
			for(int i = 0; i < 4; i++) {
				int nextr = r + dr[i];
				int nextc = c + dc[i];
				pair<int, int> next = { nextr, nextc };
				if (0 <= nextr && nextr < n && 0 <= nextc && nextc < n
						&& baby.canMove(next) && costs[nextr][nextc] > cost+1){
					if (baby.canEat(next) && minCost >= cost+1 && tgt.first >= nextr && tgt.second >= nextc) {
						tgt = next;
						minCost = cost + 1;
					}
					costs[nextr][nextc] = cost + 1;
					q.push({ nextr,nextc,cost + 1 });
				}
			}
		}
		if (minCost != INF) {
			answer += minCost;
			baby.eat(tgt);
			baby.pos = tgt;			
		}
		else {
			needHelp = true;
		}
		
	}
	cout << answer;
	return 0;
}