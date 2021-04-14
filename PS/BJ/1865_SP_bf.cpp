#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_V = 501;
int V;
vector<vector<pair<int, int>>> adj;

bool bellmanFord(int src) {
	//음수 사이클이 있다면 빈벡터를 반환할것임
	vector<int> upper(V, 987654321);
	upper[src] = 0;
	bool updated;

	for (int iter = 0; iter < V; ++iter) {
		updated = false;
		for (int here = 0; here < V; ++here) {
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				if (upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
	if (updated) return true;
	return false;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		adj.assign(MAX_V, vector<pair<int, int>>());
		int m,w;
		cin >> V >> m >> w;
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			a--; b--;
			adj[a].push_back({ b, d });
			adj[b].push_back({ a, d });
		}
		for (int i = 0; i < w; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			a--; b--;
			adj[a].push_back({ b, -d });
		}
		if (bellmanFord(0)) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}


