#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> sp(vector<vector<pair<int, int>>>& graph, int start) {
	vector<int> result(graph.size(), 987654321);
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
    int v, e;
    cin >> v >> e;
	int start;
	cin >> start;
	vector<vector<pair<int, int>>> graph(v);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a>> b>> c;
		a--; b--;
		graph[a].push_back({ c,b });
	}
    vector<int> ans = sp(graph, start-1);
	for (int i : ans) {
		if (i == 987654321) {
			cout << "INF\n";
		}
		else {
			cout << i << "\n";
		}
	}
    return 0;
}


