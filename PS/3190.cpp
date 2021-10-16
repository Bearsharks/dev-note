#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

void print(vector<vector<int>>& v) {
	cout << "\n";
	int n = v.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j];
		}
		cout << "\n";
	}

}
class Bam {
public:
	Bam(vector<vector<int>>& map_) : map(map_), n(map_.size()) {
		q.push({ 0,0 });
	}
	bool goNext() {
		pair<int, int> head = q.back();
		int nextr = head.first + d.first;
		int nextc = head.second + d.second;
		if (0 <= nextr && nextr < n && 0 <= nextc && nextc < n) {
			if (map[nextr][nextc] == 1) return false;
			if (map[nextr][nextc] != 2) {
				pair<int, int> tail = q.front(); q.pop();
				map[tail.first][tail.second] = 0;
			}
			q.push({ nextr,nextc });
			map[nextr][nextc] = 1;
		}
		else {
			return false;
		}
		return true;
	}
	void turnClockwise() {
		d = { d.second, -d.first };
	}
	void turnRClockwise() {
		d = { -d.second, d.first };
	}
private:
	pair<int, int> d = { 0,1 };
	queue<pair<int, int>> q;
	vector<vector<int>>& map;
	int n;
};
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(n,0));
	map[0][0] = 1;
	for (int i = 0; i < m;i++) {
		int a, b;
		cin >> a>> b;
		map[a-1][b-1] = 2;
	}
	Bam bam(map);
	queue<pair<int, char>> rots;
	int rotn;
	cin >> rotn;
	for (int i = 0; i < rotn;i++) {
		int a;
			char b;
		cin >> a >> b;
		rots.push({ a,b });
	}
	int t = 0;
	while (bam.goNext()) {
		t++;
		if (rots.size() && rots.front().first == t) {
			if (rots.front().second == 'D') bam.turnClockwise();
			else bam.turnRClockwise();
			rots.pop();
		}
	}
	cout << t+1;
	return 0;
}