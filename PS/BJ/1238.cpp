#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> sp(vector<vector<pair<int, int>>> graph, int start) {
	vector<int> result(graph.size(), INT_MAX);
	result[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();
		int cost = -cur.first;
		int curidx = cur.second;
		if (cost > result[curidx]) continue;

		for (pair<int, int> adj : graph[curidx]) {
			if (result[adj.second] > cost + adj.first) {
				result[adj.second] = cost + adj.first;
				pq.push({ -(cost + adj.first), adj.second });
			}
		}
	}

	return result;
}

void fwsp(vector<vector<int>>& adj) {
	int n = adj.size();
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (adj[i][k] == 123456789) continue;
			for (int j = 0; j < n; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m,x;
	cin >> n >> m >> x;

	vector<vector<int>> v(n+1,vector<int>(n+1,123456789));
	for (int i = 0; i <= n; i++) {
		v[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a][b] = c;
	}
	fwsp(v);
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(v[i][x] + v[x][i], answer);
	}
	cout << answer;
	return 0;
}