#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

class DSU {
public:
	DSU() {
	}
	DSU(int n) :parent(n), rank(n, 1), size(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}
	int merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return v;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		size[v] += size[u];
		if (rank[u] == rank[v]) rank[v]++;
		return v;
	}
	void makeSet() {
		int i = parent.size();
		parent.push_back(i);
		rank.push_back(1);
		size.push_back(1);
	}
	int getSize(int u) {
		return size[find(u)];
	}
private:
	vector<int> parent;
	vector<int> rank;
	vector<int> size;
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int v, e;
	cin >> v >> e;
	vector<tuple<long long, int,int>> edge;
	DSU dsu(v+1);

	for (int i = 0; i < e; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		if (a > b) swap(a, b);
		edge.push_back(tuple<long long, int, int>(cost, a, b));
	}
	sort(edge.begin(), edge.end());
	long long answer = 0;
	for (int i = 0; i < e; i++) {
		int a = get<1>(edge[i]);
		int b = get<2>(edge[i]);
		if (dsu.find(a) == dsu.find(b)) continue;
		answer += get<0>(edge[i]);
		if (dsu.merge(a, b)) {
			if (dsu.getSize(a) == v) break;
		}
	}
	cout << answer;
	return 0;
}