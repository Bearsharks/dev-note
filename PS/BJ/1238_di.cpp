#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> sp(vector<vector<pair<int, int>>>& graph, int start) {
	vector<int> result(graph.size(), 123456789);
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
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m, x;
	cin >> n >> m >> x;

	vector<vector<pair<int, int>>> v(n + 1);
	vector<vector<pair<int, int>>> bv(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ c,b});
		bv[b].push_back({ c,a});
	}
	vector<int> fs = sp(v, x);
	vector<int> bs = sp(bv, x);
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(fs[i] + bs[i], answer);
	}
	cout << answer;
	return 0;
}