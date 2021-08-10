#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

bool bfs(vector<vector<int>>& v, vector<int>& color) {
	for (int i = 1; i < v.size(); i++) {
		if (color[i] != -1) continue;
		queue<pair<int, int>> q;
		q.push({ i,0 });
		color[i] = 0;
		while (!q.empty()) {
			int cur = q.front().first;
			bool curColor = q.front().second;
			q.pop();
			for (int node : v[cur]) {
				if (color[node] == -1) {
					color[node] = !curColor;
					q.push({ node,!curColor });
				}
				else if (color[node] == curColor) return false;
			}
		}
	}
	
	return true;
}
int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, e;
		cin >> n >> e;
		vector<vector<int>> v(n + 1);
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);

		}
		vector<int> color(n+1,-1);
		if (bfs(v, color)) cout << "YES\n";
		else  cout << "NO\n";
	}
	return 0;
}